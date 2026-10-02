/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** tests_serv
*/

#include "server.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(start_server_zappy, test_start_server_zappy)
{
    server_t server;
    client_t client[MAX_CLIENTS] = {0};
    char *argv[7] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10"};

    cr_assert_eq(start_server_zappy(&server, client, argv), 0);
}

