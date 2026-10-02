/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** get_client_by_id
*/

#include "server.h"

client_t *get_client_by_id(client_t *clients, int id)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].id == id)
            return &clients[i];
    }
    return NULL;
}
