#!/usr/bin/env python3

from sys import argv, exit, stderr

from ai.src.trantorians import Trantorian
import ai.src.error_handling as error_handling

def main():
    '''Main function'''

    if len(argv) == 2 and argv[1] == "-help":
        error_handling.print_usage()
        exit(0)
    if len(argv) != 7:
        print("Error: bad arguments", file=stderr)
        exit(84)

    client_info: list = error_handling.check_param(argv[1:])

    ai_bot = Trantorian()
    ai_bot.start_tratorian(client_info)
    #info = ServerClient(client_info[0], client_info[1])
    #info.connect_to_server()

    #info.request.ask_to_go_forward(info.client_socket)
    #info.request.ask_to_go_right(info.client_socket)
    #info.request.ask_to_go_left(info.client_socket)
    #info.request.ask_to_inventory(info.client_socket)
    #info.request.ask_to_look(info.client_socket)
    #info.close_connection()

    return 0

if __name__ == "__main__":
    exit(main())