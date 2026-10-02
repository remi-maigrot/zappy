/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** init_lists
*/

#include "server.h"

int manage_all_list(server_t *server)
{
    init_list(&(server->client_list));
    init_list(&(server->graphic_list));
    return 0;
}
