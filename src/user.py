#!/usr/bin/python
# -*- coding: utf-8 -*-


class User:
    def __init__(self):
        self.id = None
        self.locationRequest = None

    def requestMap(self):
        self.id = input("ID: ")
        self.locationRequest = input("Location: ")
        return self.id, self.locationRequest
        pass

