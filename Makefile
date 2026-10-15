##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## root
##

SRC	        =	src/main.cpp	\
				src/Circuit.cpp	\
				src/IComponent.cpp 	\
				src/Parser.cpp 		\
				src/ComponentFactory.cpp 	\
				src/AComponent.cpp 	\
				src/DoOperation.cpp 	\
				src/ElementaryComponent.cpp 	\
				src/SpecialComponent.cpp 		\
				src/SpecialComponent/Input.cpp 	\
				src/SpecialComponent/Output.cpp 	\
				src/SpecialComponent/True.cpp 	\
				src/SpecialComponent/False.cpp 	\
				src/SpecialComponent/Clock.cpp 	\
				src/ElementaryComponent/And.cpp 	\
				src/ElementaryComponent/Or.cpp 	\
				src/ElementaryComponent/Xor.cpp 	\
				src/ElementaryComponent/Not.cpp 	\
				src/GatesComponent.cpp 		\
				src/GatesComponent/Comp4030.cpp	\
				src/GatesComponent/Comp4001.cpp	\
				src/GatesComponent/Comp4011.cpp	\
				src/GatesComponent/Comp4069.cpp	\
				src/GatesComponent/Comp4071.cpp	\
				src/GatesComponent/Comp4081.cpp	\
				src/AdvancedComponent/Comp4008.cpp	\
				src/AdvancedComponent/Comp4512.cpp	\
				src/AdvancedComponent/Comp4013.cpp	\
				src/AdvancedComponent/Comp4040.cpp	\
				# src/AdvancedComponent/Logger.cpp	\
				# src/AdvancedComponent/Comp4801.cpp	\
				# src/AdvancedComponent/Comp4514.cpp	\
				# src/AdvancedComponent/Comp4094.cpp	\
				# src/AdvancedComponent/Comp4017.cpp	\
				# src/AdvancedComponent/Comp2716.cpp	\

OBJ	        =	$(SRC:.cpp=.o)

NAME	    =	nanotekspice

CC 		    =	g++

CPPFLAGS	=	-I ./src -I ./src/SpecialComponent -I ./src/GatesComponent -I ./src/ElementaryComponent -I ./src/AdvancedComponent

# CFLAGS      =   -Wall -Wextra
CFLAGS      =   -std=c++20 -Wall -Wextra -Werror -g3

all : $(NAME)

$(NAME) :	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	find -name '*~' -delete -o -name '#*#' -delete

re : fclean all

tests_run:
	$(CC) $(OBJ) $(TSRC) --coverage -lcriterion -I ./includes/ -o unit_tests

coverage:
	gcovr --exclude tests/

.PHONY: re clean fclean all tests_run coverage
