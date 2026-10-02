##
## EPITECH PROJECT, 2023
## B-CNA-410-BDX-4-1-groundhog-eleonore.bonaventure
## File description:
## Makefile
##

SRC	=	main.py

NAME	=	zappy_ai

all:	$(NAME)
PHONY	+=	all

$(NAME):
	@cp $(SRC) $(NAME)
	@chmod +x $(NAME)
	@mv $(NAME) ../

tests_run:
	@python3 -m unittest discover tests
	@echo "No tests"

clean:
	@rm -f ../$(NAME)

fclean:
	@rm -f ../$(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all