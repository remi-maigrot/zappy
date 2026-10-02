/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ai_cmd_for_gui
*/

#include "server.h"

void pex(server_t *server, client_t *client)
{
    int id = client->id;

    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client[i].is_gui == true) {
            dprintf(client[i].fd, "pex %d\n", id);
        }
    }
}

void pbc(server_t *server, client_t *client, char *msg)
{
    int id = client->id;

    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client[i].is_gui == true) {
            dprintf(client[i].fd, "pbc %d %s\n", id, msg);
        }
    }
}
