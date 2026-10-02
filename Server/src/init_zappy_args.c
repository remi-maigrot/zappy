/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** init_zappy_args
*/

#include "server.h"

static int stocking_args_freq(server_t *server, char **argv, int index)
{
    if (!server)
        return 84;
    switch (argv[index][1]) {
        case 'f':
            server->freq = atoi(argv[index + 1]);
            break;
        default:
            break;
    }
    return 0;
}

static void add_port(int port, server_t *server)
{
    if (!server)
        return;
    if (port < 1024 || port > 65535) {
        printf("Invalid port, must be between 1024 and 65535\n");
        return;
    }
    server->port = port;
}

void stocking_args(char **argv, int index, server_t *server)
{
    switch (argv[index][1]) {
        case 'p':
            add_port(atoi(argv[index + 1]), server);
            break;
        case 'x':
            server->width = atoi(argv[index + 1]);
            break;
        case 'y':
            server->height = atoi(argv[index + 1]);
            break;
        case 'n':
            add_teams(argv, index + 1, server);
            break;
        case 'c':
            server->clients_nb = atoi(argv[index + 1]);
            break;
        default:
            break;
    }
    stocking_args_freq(server, argv, index);
}
