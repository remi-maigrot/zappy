/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** display.cmds
*/

#include "server.h"

int arr_length(int *arr)
{
    int i = 0;

    if (!arr)
        return (0);
    for (; arr[i] != -1; i++);
    return (i);
}

void look_cmd(server_t *server, client_t *client, char **cmd)
{
    return;
}

void inventory_cmd(server_t *server, client_t *client, char **cmd)
{
    if (!server || !client || !cmd)
        return;
}

void broadcast_cmd(server_t *server, client_t *client, char **cmd)
{
    if (!server || !client || !cmd)
        return;
    dprintf(client->fd, "ok\n");
}
