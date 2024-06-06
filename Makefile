##
## EPITECH PROJECT, 2024
## B-YEP-400-MAR-4-1-zappy-alexandre.vittenet
## File description:
## Makefile
##


all: server ai gui

server:
	@echo -e "\033[32m[Compiling SERVER...]\033[0m"
	@make -sC ./SERVER
	@mv ./SERVER/zappy_server .

ai:
	@echo -e "\033[30m[Compiling AI...]\033[0m"
	@make -sC ./AI
	@mv ./AI/zappy_ai .

gui:
	@echo -e "\033[34m[Compiling GUI...]\033[0m"
	@make -sC ./GUI
	@mv ./GUI/zappy_gui .

clean: clean_server clean_ai clean_gui

clean_server:
	@rm -f zappy_server

clean_ai:
	@rm -f zappy_ai

clean_gui:
	@rm -f zappy_gui

fclean:
	@make -s clean

re: fclean all
