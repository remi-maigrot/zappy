/*
** EPITECH PROJECT, 2023
** B-NWP-400-BDX-4-1-myftp-evan.lacoste
** File description:
** check_fd
*/

#include "server.h"

static int set_fd_client_tab(server_t *server, client_t *clients)
{
    if (!server || !clients)
        return 84;
    for (int i = 1; i < MAX_CLIENTS; i++) {
        if (clients[i].fd != -1) {
            FD_SET(clients[i].fd, &(server->rd));
            server->max_fd = (clients[i].fd > server->max_fd) ?
            clients[i].fd : server->max_fd;
            clients[i].id = i;
        }
    }
    return 0;
}

void set_fd(server_t *server, client_t *clients)
{
    FD_ZERO(&(server->rd));
    FD_SET(server->fd, &(server->rd));
    server->max_fd = server->fd;
    set_fd_client_tab(server, clients);
    back_to_start(&server->client_list);
}
