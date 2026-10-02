/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** loop_server
*/

#include "server.h"

int reset_timeval(server_t *server)
{
    double freq = server->freq;
    double res = 1 / freq;

    if (!server)
        return 84;
    if (!server->tv.tv_sec && !server->tv.tv_usec) {
        server->new_tick = true;
        server->tv.tv_sec = res;
        server->tv.tv_usec = res * 1000000.0;
    }
    return 0;
}

static void inc_request_count_command(server_t *server, client_t *clients,
int i)
{
    if (server->status > 0 && !FD_ISSET(clients[i].fd, &server->rd)) {
        clients[i].request_count++;
    }
}

static void handle_clients(server_t *server, client_t *clients,
game_info_t *game_info)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].fd != -1 && clients[i].request_count > 10) {
            continue;
        }
        handle_client(server, &clients[i], game_info);
        inc_request_count_command(server, clients, i);
    }
}

int loop_server(server_t *server, struct sockaddr_in addr_serv,
    client_t *clients, game_info_t *game_info)
{
    if (!server || !clients) return 84;
    server->status = select(server->max_fd + 1, &server->rd,
    NULL, NULL, &(server->tv));
    if (server->status == -1) {
        perror("select");
        return 0;
    } else
        server->new_tick = false;
    if (FD_ISSET(server->fd, &server->rd))
        accept_socket(server, addr_serv, clients);
    handle_clients(server, clients, game_info);
    if (server->new_tick) {
        refill_map(server, game_info);
        remove_food(server, clients, game_info);
    }
    return 0;
}
