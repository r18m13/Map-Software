#!/usr/bin/python
# -*- coding: utf-8 -*-
import cv2
import os
from matplotlib import pyplot as plt
import numpy as np
from skimage.measure import ransac
from skimage.transform import FundamentalMatrixTransform
import g2o
import sensor
import featureExtractor
import robot
import graph
import networkx as nx

# Create a graph
G = nx.Graph()

class SLAMSystem:
    def __init__(self):
        self.graph = None
        self.sensors = None
        self.robot = None

    def handleRequest(self, call):
        #handling involves the prompt of the sensor description (in this case path to the video)
        if call:
            print("Trigger")
            self.sensors = sensor.Sensor.acquireData(sensor)
            return self.sensors
        else:
            print("No call made!")
            pass
    
    

    def performSLAM(self, path_data):
        cam = cv2.VideoCapture(path_data) #The file must be placed in the Map-Software Directory

        # Get the frames per second (fps) of the video
        fps = cam.get(cv2.CAP_PROP_FPS)

        # Calculate the interval in frames (for 0.2 seconds)
        frame_interval = int(fps*0.2)  # 0.2 seconds

        try:
            # creating a folder named temp_data
            if not os.path.exists('temp_data'):
                os.makedirs('temp_data')

            # if not created then raise error
        except OSError:
            print('Error: Creating directory of temp_data')

            # Frame counter
        currentframe = 0
        pose_0 = np.eye(4)
        e_arr = np.array([0, 0, 0, 1])
        i = 0
        j = 1
        i, j = graph.Graph.addEdge(G, i, j, pose_0)
        positions = [
                        pose_0[:3, 3],  # Position of Frame 0
                    ]
        count = 1

        while True:

                # Set the position of the next frame to capture
            cam.set(cv2.CAP_PROP_POS_FRAMES, currentframe)

                # Reading from frame
            res, frame = cam.read()

                #Temporary Frame Init
            tempframe = currentframe + frame_interval
            
            cam.set(cv2.CAP_PROP_POS_FRAMES, tempframe)
            res2, frame_1 = cam.read()

            #name = './temp_data/frame' + str(currentframe) + '.jpg'
            #print("create")

            #cv2.imwrite(name, frame)
            #print("done")
            #print ("Init")
            #print(res)

            if res2:
            #print("test")
                feature = featureExtractor.FeatureExtractor
                extracted_R, extracted_t = featureExtractor.FeatureExtractor.extractFeatures(feature, res2, frame, frame_1)
                currentframe += frame_interval
                #print (extracted_R)
                #print("---------------")
                #print(extracted_t)
            
                temp_arr = np.hstack((extracted_R, extracted_t))
                temp_arr = np.vstack((temp_arr, e_arr))

                #slam.graph = temp_arr      
                #print(slam.graph)

                        
                pose_1 = temp_arr
                pose_temp = robot.Robot.updatePoseAndMap(pose_0, pose_1)
                print(count)
                print(pose_temp)
            
                pose_0 = pose_temp

                graph.Graph.addNode(G, j, pose_temp)
                i , j = graph.Graph.addEdge(G, i, j, pose_1)

                positions.append(pose_temp[:3, 3])

                count += 1

            else:
                positions = np.array(positions)
                return positions
                cam.release()
                cv2.destroyAllWindows()
                break


    def generateMap(self, positions):
        plt.figure(figsize=(8, 6))
        plt.plot(positions[:, 0], positions[:, 1], 'o-', label="Robot Trajectory")
        plt.legend()
        plt.grid()
        plt.show()
        pass

#------------Testing----------------
if __name__ == '__main__':
    slam = SLAMSystem()
    path = SLAMSystem.handleRequest(SLAMSystem, call=True)
    print(path)
    path = path.strip()

    p_arr = SLAMSystem.performSLAM(SLAMSystem, path)

    #----------GRAPH---------
    SLAMSystem.generateMap(SLAMSystem, p_arr)

    
    

    



   