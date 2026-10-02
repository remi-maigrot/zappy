#!/usr/bin/env python3

##
## EPITECH PROJECT, 2023
## Zappy AI
## File description:
## Custom exceptions classes
##

class InvalidPortError(Exception):
    '''Exception raised when port is invalid'''

    def __init__(self, message):
        super().__init__(message)

class InvalidNameError(Exception):
    '''Exception raised when name is invalid'''

    def __init__(self, message):
        super().__init__(message)

class InvalidArgumentError(Exception):
    '''Exception raised when argument is invalid'''

    def __init__(self, message):
        super().__init__(message)

class InvalidCommandError(Exception):
    '''Exception raised when command is invalid'''

    def __init__(self, message):
        super().__init__(message)

class InvalidResponseError(Exception):
    '''Exception raised when response is invalid'''

    def __init__(self, message):
        super().__init__(message)

class ConnectionError(Exception):
    '''Exception raised when connection failed'''

    def __init__(self, message):
        super().__init__(message)
