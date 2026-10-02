##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## tests_parsing
##

from sys import path
path.append("..")

from io import StringIO
from argparse import ArgumentTypeError
from src.error_handling import check_param
import unittest
import sys


class CommandLineArgumentParsingTests(unittest.TestCase):

    def setUp(self):
        '''Capture stdout and stderr'''

        self.stdout = sys.stdout
        self.stderr = sys.stderr
        sys.stdout = StringIO()
        sys.stderr = StringIO()

    def tearDown(self):
        '''Restore stdout and stderr'''

        sys.stdout = self.stdout
        sys.stderr = self.stderr

    def test_valid_args(self):
        '''Test if the arguments are correctly parsed and valid'''

        sys.argv = ["zappy_ai", "-p", "2222", "-n", "lolo", "-h", "localhost"]
        import zappy_ai

        captured_output = sys.stdout.getvalue()
        self.assertIn("Port: 2222", captured_output)
        self.assertIn("Name: lolo", captured_output)
        self.assertIn("Host: localhost", captured_output)

    def test_invalid_args(self):
        '''Test if the arguments are correctly parsed and invalid'''

        sys.argv = ["zappy_ai", "-p", "2222", "-n", "lolo", "-h", "localhost", "-t", "toto"]
        import zappy_ai

        captured_output = sys.stderr.getvalue()
        self.assertIn("Port: 2222", captured_output)
        self.assertIn("Name: lolo", captured_output)
        self.assertNotIn("Host:", captured_output)

    def test_invalid_port(self):
        '''Test if the port is invalid'''

        sys.argv = ["zappy_ai", "-p", "abc", "-n", "John", "-h", "localhost"]
        with self.assertRaises(ArgumentTypeError):
            import zappy_ai

    def test_zero_args(self):
        '''Test if no arguments are given'''
        sys.argv = ["zappy_ai"]
        import zappy_ai

        captured_output = sys.stdout.getvalue()
        self.assertNotIn("Port:", captured_output)
        self.assertNotIn("Name:", captured_output)
        self.assertNotIn("Host:", captured_output)

if __name__ == "__main__":
    unittest.main()
