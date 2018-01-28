#!/usr/bin/env python


class CommandoError(Exception):
    pass


class MessageError(CommandoError):
    pass


class ProtocolError(MessageError):
    pass
