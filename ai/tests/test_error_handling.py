##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## test_error_handling
##

from sys import path
path.append("..")

import src.error_handling as error_handling
import unittest

class TestErrorHandling(unittest.TestCase):

    def test_check_port_upper(self):
        '''Test if port is upper 65535'''

        self.assertRaises(ValueError, error_handling.check_port, "65536")

    def test_check_port_lower(self):
        '''Test if port is lower 1024'''

        self.assertRaises(ValueError, error_handling.check_port, "1023")

    def test_check_port_is_string(self):
        '''Test if port is a string'''

        self.assertRaises(ValueError, error_handling.check_port, "test")

    def test_check_port_is_good(self):
        '''Test if port is good'''

        result = error_handling.check_port("1024")

        self.assertEqual(1024, result)


if __name__ == '__main__':
    unittest.main()