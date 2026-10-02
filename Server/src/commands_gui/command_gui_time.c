/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** command_gui_time
*/

#include "server.h"

void sgt(server_t *server, client_t *client,
game_info_t *game_info, char **cmd)
{
    if (!server || !client || !game_info || !cmd)
        return;
    dprintf(client->fd, "sgt %d\n", server->freq);
}

void sst(server_t *server, client_t *client,
game_info_t *game_info, char **cmd)
{
    if (!cmd[1] || !server || !client || !game_info)
        return;
    server->freq = atoi(cmd[1]);
    dprintf(client->fd, "sst %d\n", server->freq);
}
