#!/usr/bin/python
# -*- coding: utf-8 -*-

class Sensor:
    def __init__(self):
        self.type = None
        self.data = None

    def acquireData(self):
        self.data = input("Give the Path to the Data")
        #print (self.data)
        return self.data
        pass

if __name__ == "__main__":
    sensor = Sensor
    Sensor.acquireData(sensor)

    