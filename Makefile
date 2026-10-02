##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## Makefile
##

all:
	make -C Server
	make -C GUI
	make -C ai

server:
	make -C Server

# client:
# 	make -C ai

graphicals:
	make -C GUI

clean:
	make clean -C Server
	make clean -C GUI
	make clean -C ai

fclean:
	make fclean -C Server
	make fclean -C GUI
	make fclean -C ai

tests_run:
	make tests_run -C Server
	make tests_run -C GUI
# make tests_run -C ai

re:
	make re -C Server
	make re -C GUI
	make re -C ai

.PHONY: all server client graphicals clean fclean re

