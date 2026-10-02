##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## Core GUI Makefile
##

SRC			=	Core/Core.cpp				\
				Core/Commands.cpp			\
				Server/ServerProtocol.cpp	\
				Server/Socket.cpp			\
				Utils/Split.cpp				\
				Utils/Orientation.cpp		\
				Views/Sfml.cpp				\
				Views/Components/Tile.cpp	\
				Views/Components/Player.cpp	\

OBJ			=	$(addprefix src/, $(SRC:.cpp=.o))
OBJ			+=	$(COMMON_SRC:.cpp=.o)

NAME		=	zappy_gui

CXXFLAGS	+=	-std=c++17

CPPFLAGS	=	-I./include -W -Wall -Wextra -Wshadow -Wimplicit -Werror -pedantic

LDFLAGS		=	-lsfml-graphics -lsfml-window -lsfml-network -lsfml-system -lsfml-audio

UNIT_TESTS 	=	tests/yes.c

all:			$(NAME)

$(NAME):		$(OBJ)
				g++ -o ../$(NAME) src/main.cpp $^ $(CPPFLAGS) $(LDFLAGS) $(CXXFLAGS)

clean:
				@find . -type f | xargs touch
				@rm -f $(OBJ)
				@rm -f *.o
				@rm -f *~
				@rm -f vgcore*
				@rm -f #*
				@rm -f *.gcda
				@rm -f *.identifier
				@rm -f *.gcno

debug: CPPFLAGS += -g -ggdb3
ifeq ($(UNAME), Darwin)
	debug: CPPFLAGS += -fsanitize=address
endif
debug: 			re

tests_run:		LDFLAGS	+=	--coverage -lcriterion
tests_run:		$(OBJ)
				g++ -o unit_tests $(UNIT_TESTS) $^ $(CPPFLAGS) $(LDFLAGS)
				./unit_tests

fclean: 		clean
				rm -f ../$(NAME)
				@rm -f covr/*.html
				@rm -f covr/*.css
				@rm -rf covr/
				@rm -f *.gcno

re:				fclean all

.PHONY:			all clean tests_run all re