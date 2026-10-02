##
## EPITECH PROJECT, 2022
## Linked List lib
## File description:
## Makefile
##

SRC		=	create.c			\
			delete_node.c		\
			destroy.c			\
			length.c			\
			push.c				\
			restart.c			\

OBJ		=	$(SRC:.c=.o)

NAME 	=	liblinkedlist.a

CFLAGS	=	-w -Wall -Wextra -Werror -Wshadow -Wimplicit -pedantic

CPPFLAGS	+=	-I./

all:		$(NAME)
.PHONY:	all

UNAME := $(shell uname)

$(NAME): $(OBJ)
		@echo "Building $(NAME)..."
		@if [ "$(UNAME)" = "Darwin" ]; then \
			libtool -o $(NAME) -static $(OBJ) > /dev/null 2>&1; \
		else \
			ar rc -o $(NAME) $(OBJ) > /dev/null 2>&1; \
		fi
		@mv $@ ../
		@mkdir -p ../../include
		@cp linked_lists.h ../../include/
		@echo "$(NAME) built successfully."

debug:	CPPFLAGS	+=	-g
debug:	$(NAME)

clean:
			rm -f $(OBJ)
.PHONY:	clean

fclean: 	clean
			rm -f ../$(NAME)
			rm -f ../../include/linked_lists.h
.PHONY:	fclean

re:			fclean all
.PHONY:	re
