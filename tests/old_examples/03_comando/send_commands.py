#!/usr/bin/env python

import sys
import time

import serial

try:
    import pycommando
except ImportError:
    sys.path.append('../../')
    import pycommando

port = serial.Serial('/dev/ttyACM0', 9600)
time.sleep(1)  # wait for arduino
port.setDTR(level=0)
time.sleep(1)

h = pycommando.handlers.StreamHandler(port)

print("\t<- from computer, -> = from arduino")


def show(bs):
    print("->%r" % bs)

h.receive_message = show

for msg in ('\x00', '\x01', '\x02'):
    print("<-%r" % msg)
    h.send_message(msg)
    h.handle_stream()
