##
## EPITECH PROJECT, 2022
## B-OOP-400-PAR-4-1-tekspice-laetitia.bousch
## File description:
## Makefile
##

SRC			=	src/component/C4001.cpp
SRC			+=	src/component/C4011.cpp
SRC			+=	src/component/C4030.cpp
SRC			+=	src/component/C4069.cpp
SRC			+=	src/component/C4071.cpp
SRC			+=	src/component/C4081.cpp
SRC			+=	src/component/Clock.cpp
SRC			+=	src/component/False.cpp
SRC			+=	src/component/Input.cpp
SRC			+=	src/component/Output.cpp
SRC			+=	src/component/True.cpp
SRC			+=	src/gates/And.cpp
SRC			+=	src/gates/Nand.cpp
SRC			+=	src/gates/Nor.cpp
SRC			+=	src/gates/Or.cpp
SRC			+=	src/gates/Xor.cpp
SRC			+=	src/gates/Inverter.cpp
SRC			+=	src/parser/File.cpp
SRC			+=	src/Factory.cpp
SRC			+=	src/Circuit.cpp
SRC			+=	src/main.cpp

OBJ			=	$(SRC:.cpp=.o)

NAME		=	nanotekspice

CFLAGS		=	-std=c++20 -Wall -Wextra -Werror

CPPFLAGS	=	-iquote ./include -iquote ./include/component -iquote ./include/gates

CC			=	g++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

debug: CPPFLAGS += -g3
debug: all

clean:
	$(RM) $(NAME) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

./PHONY: all clean fclean