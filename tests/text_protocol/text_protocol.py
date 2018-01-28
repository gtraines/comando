#!/usr/bin/env python

import time

import serial

import pycommando

com = pycommando.Commando(serial.Serial('/dev/ttyACM0', 9600))
text = pycommando.protocols.TextProtocol(com)

com.register_protocol(0, text)


def show(text):
    print text

text.register_callback(show)

while True:
    com.handle_stream()
    time.sleep(0.01)
