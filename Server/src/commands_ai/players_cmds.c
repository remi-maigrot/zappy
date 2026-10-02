/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** players_cmds
*/

#include "server.h"

void take_cmd(server_t *server, client_t *client, char **cmd)
{
    if (!server || !client || !cmd)
        return;
    dprintf(client->fd, "ok\n");
}

void set_cmd(server_t *server, client_t *client, char **cmd)
{
    if (!server || !client || !cmd)
        return;
    dprintf(client->fd, "ok\n");
}

void inventory_cmd(server_t *server, client_t *client, char **cmd)
{
    if (!server || !client || !cmd)
        return;
    dprintf(client->fd, "[food %d, linemate %d, deraumere %d, sibur %d, \n"
        "mendiane %d, phiras %d, thystame %d]\n", client->inventory[0],
        client->inventory[1], client->inventory[2], client->inventory[3],
        client->inventory[4], client->inventory[5], client->inventory[6]);
}
