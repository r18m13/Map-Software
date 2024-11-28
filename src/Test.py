import user
import sLAMSystem
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

if __name__ == "__main__":
    identity, request = user.User.requestMap(user)
    print(identity, request)

    if identity and request != None:
        call = True

    else:
        call = False
    
    slam = sLAMSystem.SLAMSystem()
    path = sLAMSystem.SLAMSystem.handleRequest(sLAMSystem.SLAMSystem, call)
    print(path)
    path = path.strip()

    p_arr = sLAMSystem.SLAMSystem.performSLAM(sLAMSystem.SLAMSystem, path)

    #----------GRAPH---------
    sLAMSystem.SLAMSystem.generateMap(sLAMSystem.SLAMSystem, p_arr)
