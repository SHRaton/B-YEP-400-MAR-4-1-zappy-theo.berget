##
## EPITECH PROJECT, 2024
## B-CCP-400-MAR-4-1-panoramix-luca.giglio
## File description:
## Makefile
##

SRC	=	*.cpp

NAME	=	zappy

all:	$(NAME)

$(NAME):	$(SRC)
	g++ -o $(NAME) $(SRC) -lsfml-graphics -lsfml-window -lsfml-system -g3

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)
	make clean

re: fclean all
