##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## test_exceptions
##

from sys import path
path.append("..")

import src.exceptions as e
import unittest

def test_port(port: int):
    '''Test if port is upper 65535'''
    if port > 65535:
        raise e.InvalidPortError("Invalid port: needs to be smaller than 65535")
    elif port < 0:
        raise e.InvalidPortError("Invalid port: needs to be greater than 0")
    else:
        print("Port is valid")

def test_name_is_valid(name: str):
    '''Test if name is valid'''
    if len(name) > 32:
        raise e.InvalidNameError("Invalid name: needs to be smaller than 32")
    if len(name) < 1:
        raise e.InvalidNameError("Invalid name: needs to be greater than 0")
    if name.isalnum() == False:
        raise e.InvalidNameError("Invalid name: needs to be alphanumeric")
    else:
        print("Name is valid")

class TestException(unittest.TestCase):

    def test_exception_port_upper(self):
        '''Test if port is upper 65535'''

        with self.assertRaises(e.InvalidPortError):
            test_port(9999999)

    def test_exception_port_lower(self):
        '''Test if port is lower 0'''

        with self.assertRaises(e.InvalidPortError):
            test_port(-1)

    def test_exception_port_valid(self):
        '''Test if port is valid'''

        self.assertEqual(test_port(4242), None)

    def test_exception_name_upper(self):
        '''Test if name is upper 32'''

        with self.assertRaises(e.InvalidNameError):
            test_name_is_valid("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")

    def test_exception_name_lower(self):
        '''Test if name is lower 1'''

        with self.assertRaises(e.InvalidNameError):
            test_name_is_valid("")

    def test_exception_name_alphanumeric(self):
        '''Test if name is alphanumeric'''

        with self.assertRaises(e.InvalidNameError):
            test_name_is_valid("a!a")
if __name__ == '__main__':
    unittest.main()