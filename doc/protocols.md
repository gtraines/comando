Protocols are built on top of the base message format by imposing a structure
on the payload bytes. Protocol messages contain the following:

- protocol id [1 byte] the protocol to which this message belongs
- payload [N bytes] the additional payload

Protocol ids must be unique and can be limited to some maximum to reduce the
memory of the parser on the Arduino side. See [commando.h](https://github.com/braingram/commando/blob/master/libraries/commando/commando.h) for the MAX_PROTOCOLS define.
