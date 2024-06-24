##
## EPITECH PROJECT, 2024
## B-CCP-400-MAR-4-1-panoramix-luca.giglio
## File description:
## Makefile
##

SRC		=	src/*.cpp commands/*.cpp commands/passive/*.cpp commands/active/*.cpp

NAME	=	zappy_gui

FLAGS 	=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -g3

all:	$(NAME)

$(NAME):	$(SRC)
	@g++ -o $(NAME) $(SRC) $(FLAGS)

clean:
	@rm -f $(NAME)

fclean:
	@rm -f $(NAME)
	@make clean

re: fclean all
