/*
** EPITECH PROJECT, 2023
** Server
** File description:
** server
*/

#include "server.h"

void accept_socket(server_t *server, struct sockaddr_in addr_serv,
client_t *clients)
{
    int new_fd = accept(server->fd, (struct sockaddr *)&addr_serv,
                (socklen_t *)&server->addrlen);
    int index = 0;
    if (new_fd == -1)
        perror("accept");
    while (index < MAX_CLIENTS) {
        if (clients[index].fd == -1) {
            clients[index].fd = new_fd;
            dprintf(new_fd, "WELCOME\n");
            break;
        }
        index++;
    }
    if (index == MAX_CLIENTS)
        close(new_fd);
    server->max_fd = new_fd > server->max_fd ? new_fd : server->max_fd;
}

void handle_client(server_t *server, client_t *client, game_info_t *game_info)
{
    if (client->fd != -1) {
        if (FD_ISSET(client->fd, &server->rd)) {
            client->x = rand() % server->width;
            client->y = rand() % server->height;
            client->orientation = rand() % 4;
            handle_command(server, client, game_info);
            client->request_count = 0;
        }
    }
}

static int start_server(server_t *server, struct sockaddr_in addr_serv,
client_t *clients, game_info_t *game_info)
{
    linked_list *current_node = server->client_list;

    for (int i = 1; i < MAX_CLIENTS; i++) {
        clients[i].fd = -1;
        clients[i].request_count = 0;
        push_node(&current_node, &clients[i]);
        current_node = current_node->next;
    }
    while (true) {
        set_fd(server, clients);
        reset_timeval(server);
        loop_server(server, addr_serv, clients, game_info);
    }
    return server->status;
}

void init_addr_server(server_t *server, client_t *clients,
game_info_t *game_info)
{
    struct sockaddr_in addr_serv = {0};
    addr_serv.sin_family = AF_INET;
    addr_serv.sin_port = htons(server->port);
    addr_serv.sin_addr.s_addr = INADDR_ANY;
    if (bind(server->fd,(struct sockaddr *)
    &addr_serv, sizeof(addr_serv)) == -1) {
        perror("bind error");
        return;
    }
    if (listen(server->fd, MAX_CLIENTS) == -1) {
        perror("listen error");
        return;
    }
    for (int i = 1; i < MAX_CLIENTS; i++)
        clients[i].fd = -1;
    server->addrlen = sizeof(addr_serv);
    server->status = start_server(server, addr_serv, clients, game_info);
}

int start_server_zappy(server_t *server, client_t *clients)
{
    game_info_t *game_info = init_game_info();
    game_info->ressources = init_ressources(server->height, server->width);
    game_info->map = init_map(game_info->ressources ,server->height,
    server->width);
    spawn_ressources(game_info->ressources, game_info->map, server->height,
    server->width);
    server->fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->fd == -1) {
        perror("socket error");
        return 84;
    }
    init_addr_server(server, clients, game_info);
    shutdown(server->fd, SHUT_RDWR);
    free_all(server, clients, game_info);
    return 0;
}
