# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elagouch <elagouch@42>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/28 10:51:47 by elagouch          #+#    #+#              #
#    Updated: 2024/09/28 11:35:34 by elagouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG = rush-02
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = main.c \
      atoi.c join.c putstr.c \
      strcat.c strlen.c pow.c
OBJ = $(SRC:.c=.o)

all: $(PROG)
$(PROG): $(OBJ)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJ)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(PROG)
re: fclean all

.PHONY: all fclean re
