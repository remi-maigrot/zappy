/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** move_cmds
*/

#include "server.h"

void forward_cmd(server_t *server, client_t *client, char **cmd)
{
    if (!server || !client || !cmd)
        return;
    if (client->direction == NORTH)
        client->y = (client->y - 1 < 0) ? server->height - 1 : client->y - 1;
    if (client->direction == SOUTH)
        client->y = (client->y + 1 >= server->height) ? 0 : client->y + 1;
    if (client->direction == EAST)
        client->x = (client->x + 1 >= server->width) ? 0 : client->x + 1;
    if (client->direction == WEST)
        client->x = (client->x - 1 < 0) ? server->width - 1 : client->x - 1;
    dprintf(client->fd, "ok\n");
}

void right_cmd(server_t *server, client_t *client, char **cmd)
{
    if (!server || !client || !cmd)
        return;
    client->direction = (client->direction + 1 > WEST) ? NORTH :
        client->direction + 1;
    dprintf(client->fd, "ok\n");
}

void left_cmd(server_t *server, client_t *client, char **cmd)
{
    if (!server || !client || !cmd)
        return;
    client->direction = (client->direction - 1 < NORTH) ? WEST :
        client->direction - 1;
    dprintf(client->fd, "ok\n");
}
