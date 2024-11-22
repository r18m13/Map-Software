#!/usr/bin/python
# -*- coding: utf-8 -*-
# Importing all necessary libraries
import cv2
import os
import numpy as np
from skimage.measure import ransac
from skimage.transform import FundamentalMatrixTransform

#sensorData = "M:\Temp\PXL_20241029_172023595.mp4"
#R_arr = []
#t_arr = []

class FeatureExtractor:
    def __init__(self):
        self.extractedFeatures = []
        R_1 = 0
        t_1 = 0

    def extractFeatures(self, res2, frame, frame_1):
        fx = 270
        fy = 270
        cx = 2160/2
        cy = 3840/2

        if res2:
                #--------------Testing----------------
                orb = cv2.ORB_create(nfeatures=3000)

                keypoints1, descriptors1 = orb.detectAndCompute(frame, None)
                keypoints2, descriptors2 = orb.detectAndCompute(frame_1, None)
                
                # Initialize the BFMatcher with default params
                bf = cv2.BFMatcher(cv2.NORM_HAMMING, crossCheck=True)
 
                # Match descriptors between frame I and frame I+1
                matches = bf.match(descriptors1, descriptors2)
 
                # Sort matches by distance (best matches first)
                matches = sorted(matches, key=lambda x: x.distance)

                # Extract matched keypoints
                p1 = np.float32([keypoints1[m.queryIdx].pt for m in matches])
                p2 = np.float32([keypoints2[m.trainIdx].pt for m in matches])

 
                # Camera intrinsic parameters (example values, replace with your camera's calibration data)
                K = np.array([[fx, 0, cx],
                              [0, fy, cy],
                              [0, 0, 1]])
 
                # Compute the Fundamental matrix using RANSAC
                F, inliers = cv2.findFundamentalMat(p1, p2, cv2.FM_RANSAC)
 
                # Compute the Essential matrix using the camera's intrinsic parameters 
                E = K.T @ F @ K
 
                # Decompose the Essential matrix to get R and t
                _, R, t, mask = cv2.recoverPose(E, p1, p2, K) #SVD Decomposition

                #print (R)
                #print ("-----------")
                #print (t)

                #R_arr.append(R)
                #t_arr.append(t)

                R_1 = R
                t_1 = t

                #print (self.extractedFeatures[0])
                #print("-----------------")
                #print(self.extractedFeatures[1])
                #print(R_1, t_1)

                return R_1, t_1

        else:
            print("Error")

#if __name__ == "__main__":
    #featue = FeatureExtractor()

    #FeatureExtractor.extractFeatures(featue, sensorData)