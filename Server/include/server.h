/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** server
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "linked_lists.h"
#include "my.h"


#ifndef SERVER_H_
    #define SERVER_H_
    #define MAX_CLIENTS 6

typedef struct ressources_s {
    int max_food;
    int max_linemate;
    int max_deraumere;
    int max_sibur;
    int max_mendiane;
    int max_phiras;
    int max_thystame;
    int current_food;
    int current_linemate;
    int current_deraumere;
    int current_sibur;
    int current_mendiane;
    int current_phiras;
    int current_thystame;
} ressources_t;

typedef struct map_s {
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
    int x;
    int y;
} map_t;

typedef struct inventory_s {
    int inventory[7];
    int team_id;
    int id;
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
} inventory_t;

typedef struct client_s {
    int fd;
    int id;
    int port;
    int socket;
    fd_set rd;
    char **cmd;
    char *team_name;
    bool is_in_team;
    bool is_already_connected;
    bool is_gui;
    linked_list *commands;
    int x;
    int y;
    int orientation;
    int level;
    inventory_t *inventory;
    int request_count;
} client_t;

typedef struct server_s {
    char *ip;
    int port;
    char **teams_names;
    int clients_nb;
    int freq;
    int max_fd;
    int fd;
    struct timeval tv;
    bool new_tick;
    fd_set rd;
    int addrlen;
    int *all_fd;
    int status;
    int width;
    int height;
    int command_time_execution;
    linked_list *client_list;
    linked_list *graphic_list;
    client_t *clients;
} server_t;

typedef struct game_info_s {
    map_t **map;
    ressources_t *ressources;
} game_info_t;

typedef struct team_s {
    char *name;
    int max_clients;
    int nb_players;
} team_t;

typedef struct command_s {
    char *command;
    void (*ptr)(server_t *server, client_t *client, game_info_t *game_info,
    char **tab);
} command_t;

void usage(void);
int init_zappy(char **argv);
void free_all(server_t *server, client_t *clients, game_info_t *game_info);
client_t *init_client(void);
server_t *init_server(void);
int start_server_zappy(server_t *server, client_t *clients);
void set_fd(server_t *server, client_t *clients);
void handle_command(server_t *server, client_t *client,
game_info_t *game_info);
void accept_socket(server_t *server, struct sockaddr_in addr_serv,
client_t *clients);
void handle_client(server_t *server, client_t *client, game_info_t *game_info);
int loop_server(server_t *server, struct sockaddr_in addr_serv,
client_t *clients, game_info_t *game_info);
int spawn_ressources(ressources_t *ressources, map_t **map, int height,
int width);
game_info_t *init_game_info();
ressources_t *init_ressources(int height, int width);
map_t **init_map(ressources_t *ressources , int height, int width);
const command_t *is_ai_commands(char **cmd);
const command_t *is_gui_commands(char **cmd);
team_t *init_team(server_t *server);
void check_if_team_exist(server_t *server, client_t *client, char *cmd,
team_t *team);
void refill_map(server_t *server, game_info_t *game_info);
int reset_timeval(server_t *server);
int manage_all_list(server_t *server);
void pin(server_t *server, client_t *client,
game_info_t *game_info, char **cmd);
void ppo(server_t *server, client_t *client,
game_info_t *game_info, char **cmd);
void plv(server_t *server, client_t *client,
game_info_t *game_info, char **cmd);
void sgt(server_t *server, client_t *client,
game_info_t *game_info, char **cmd);
void sst(server_t *server, client_t *client,
game_info_t *game_info, char **cmd);
void msz(server_t *server, client_t *client,
game_info_t *game_info, char **cmd);
void bct(server_t *server, client_t *client,
game_info_t *game_info, char **cmd);
void mct(server_t *server, client_t *client,
game_info_t *game_info, char **cmd);
void tna(server_t *server, client_t *client,
game_info_t *game_info, char **cmd);
client_t *get_client_by_id(client_t *client, int id);
int remove_food(server_t *server, client_t *clients, game_info_t *game_info);
void stocking_args(char **argv, int index, server_t *server);
void add_teams(char **argv, int index, server_t *server);
void pnw(server_t *server, client_t *client);

#endif /* !SERVER_H_ */
