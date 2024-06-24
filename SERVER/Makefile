##
## EPITECH PROJECT, 2024
## B-YEP-400-MAR-4-1-zappy-alexandre.vittenet
## File description:
## Makefile
##

SRC		=	src/*.c commands/*.c commands/commands_AI/*.c commands/commands_GUI/*.c

NAME	=	zappy_server

FLAGS 	= 	-g3 -lm

all:	$(NAME)

$(NAME):	$(SRC)
	@gcc -o $(NAME) $(SRC) $(FLAGS)

clean:
	@rm -f $(NAME)

fclean:
	@rm -f $(NAME)
	@make clean

re: fclean all
