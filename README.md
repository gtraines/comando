Commando... Command your Arduino!

## Inspiration

How many times have you written a 'simple' protocol for communicating with
an Arduino that turned into anything but 'simple'? This project is meant to
solve a few goals

1. make calling commands on an Arduino from a computer (and vice versa) easy
2. remove the need to write serial protocols for transferring common datatypes
3. allow simultaneous use of multiple protocols (e.g. debug and command)

The initial inspiration came from an attempt to use cmdmessenger and finding
it difficult to send simple datatypes (e.g. floats).


## Install

To install the Python library run

```
python setup.py install
```

To install the Arduino library, copy libraries/commando to wherever your
Arduino libraries are located (~/sketchbook/libraries on linux).

## Overview

You have two devices: 1 running Python, and an Arduino. You want these to:

1. call commands on the other one
2. transfer data

This communication happens over a stream (e.g. serial port), and will follow
some structure (a protocol) that defines how data (i.e. messages) are
organized. This structure is mirrored in commando.

## Streams

A stream is the conduit through which messages are passed between Python and
the Arduino. So far, this is a serial port but could be anything that allows
passing bytes back and forth (i.e. has read, write).

## Protocols

The real power of commando comes with using protocols. Protocols are ways to
structure messages to do things like:

1. have Python trigger commands on the Arduino
2. have the Arduino trigger commands in Python

To use protocols, create a stream and handler (as above). Then register some
protocols. Some example protocols are below.

#### TextProtocol

Just sends text (byte arrays).

#### LogProtocol

Log allows the Arduino to issue Python logging-like messages and Python
to pass on these messages to the logging module.

#### CommandProtocol

Allows the Arduino to call Python functions and Python to call Arduino
functions. This is similar to the Arduino cmdmessenger library.

Commands callbacks are registered in a similar way as protocols.

### Warning about register\_message\_callback

One important note is that if you register a message callback with the handler,
all protocols will be ignored!

## Example

see examples/commands.py for a basic example
