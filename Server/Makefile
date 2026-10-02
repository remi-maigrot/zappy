##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## Makefile
##

SRC	=		usage.c \
			init_zappy.c \
			free_all.c \
			init_structs.c \
			set_fd.c \
			server.c \
			handle_command.c \
			loop_server.c \
			spawn_ressources.c \
			find_commands.c \
			init_teams.c \
			add_player_in_team.c \
			refill_map.c \
			init_lists.c \
			commands_gui/command_gui_player.c \
			commands_gui/commands_gui_maps.c \
			commands_gui/command_gui_time.c \
			get_client_by_id.c \
			init_map.c \
			manage_food.c \
			init_zappy_args.c \
			commands_gui/info_players_to_gui.c \
# commands_gui/ai_cmd_for_gui.c \

SRC_MAIN	=	main.c

OBJ	=	$(addprefix src/, $(SRC:.c=.o))

MAIN_OBJ	=	$(addprefix src/, $(SRC_MAIN:.c=.o))

NAME	=	zappy_server

LDFLAGS		+=	-L./lib -lutils -lm
LDFLAGS		+=	-L./lib -llinkedlist -lm

CPPFLAGS	=	-I./include -g -ggdb3 -W -Wall -Wextra -Wshadow -Wimplicit -Werror

UNIT_TESTS =	tests/tests_func.c \
#				 tests/tests_serv.c

UNAME := $(shell uname)

all:	lib	$(NAME)

lib:
		make -C ./lib/

lib_debug:
		make -C ./lib/ debug

$(NAME):	$(OBJ) $(MAIN_OBJ)
			gcc -o ../$(NAME) $(OBJ) $(MAIN_OBJ) $(CPPFLAGS) $(LDFLAGS)

debug: CPPFLAGS += -g -ggdb3
ifeq ($(UNAME), Darwin)
debug: CPPFLAGS += -fsanitize=address
endif
debug: fclean lib_debug $(NAME)

clean:
			make -s -C ./lib/ clean
			rm -f $(OBJ)
			rm -f $(MAIN_OBJ)

fclean: clean
			make -s -C ./lib/ fclean
			rm -f ../$(NAME)
			rm -f *.gc*
			rm -f unit_tests

tests_run:	LDFLAGS	+=	--coverage -lcriterion
tests_run:	all
			gcc -o unit_tests $(UNIT_TESTS) $(OBJ) $(CPPFLAGS) $(LDFLAGS)
			./unit_tests

re:			fclean all

.PHONY: clean all re tests_runf clean lib lib_debug
