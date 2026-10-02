##
## EPITECH PROJECT, 2023
## AI
## File description:
## error_handling
##

def print_usage() -> None:
    '''Print usage'''

    print("USAGE: ./zappy_ai -p port -n name -h machine")
    print("\tport\tis the port number")
    print("\tname\tis the name of the team")
    print("\tmachine\tis the name of the machine; localhost by default")

def check_param(argv: list) -> list:
    '''Parsing of argument / Error handling'''

    port = None
    name = None
    host = None
    info : list = []
    i : int = 0

    while i < len(argv):
        if argv[i] == '-p' and i + 1 < len(argv):
            port = int(argv[i + 1])
            i += 2
        elif argv[i] == '-n' and i + 1 < len(argv):
            name = argv[i + 1]
            i += 2
        elif argv[i] == '-h' and i + 1 < len(argv):
            host = argv[i + 1]
            i += 2
        else:
            i += 1

    info.append(port)
    info.append(name)
    info.append(host)
    return info

def check_port(port: str) -> int:
    '''Check if port is an int between 1024 and 65535'''

    try:
        port = int(port)
        if port < 1024 or port > 65535:
            raise ValueError
    except ValueError:
       #print("Error: port must be an integer")
        exit(84)
    return port

def check_name_string(name: str) -> str:
    '''Check if name of team / machine is a string'''

    if not isinstance(name, str):
        print("Error: name must be a string")
        exit(84)
    return name