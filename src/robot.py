#!/usr/bin/python
# -*- coding: utf-8 -*-

import numpy as np


class Robot:
    def __init__(self):
        self.pose = None
        self.map = None

    def updatePoseAndMap(pose_0, pose_1):
        while True:
            pose_w_1 = np.dot(pose_0, pose_1)
            #pose_w_2 = np.dot(pose_w_1, pose_2)
            return pose_w_1
        pass
