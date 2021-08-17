##
## EPITECH PROJECT, 2019
## PSU_my_sokoban_2019
## File description:
## Makefile lib
##

#flags#

CFLAGS = -Wall -Wextra -Werror -Wshadow

CPPFLAGS = -iquote $(IDIR)

DBGFLAGS = -g3 -ggdb

LDFLAGS =

#sources#

SRC =	$(wildcard fprintf/*.c && printf/*.c && *.c)

OBJ = $(SRC:.c=.o)

NAME = libmy.a

LIB = libmy.a

IDIR = .

CC = gcc

#rules#

all:    $(NAME)

$(NAME):    $(OBJ)
	ar rc $(LIB) $(OBJ)
	mv $(LIB) ../
	cp my.h ../../include/

debug: CFLAGS += $(DBGFLAGS)
debug: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(LIB)

re: fclean all

.PHONY: fclean clean re all debug
