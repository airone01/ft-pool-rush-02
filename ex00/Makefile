# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elagouch <elagouch@42>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/28 10:51:47 by elagouch          #+#    #+#              #
#    Updated: 2024/09/28 10:52:40 by elagouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG = rush-01
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = main.c \
      ft_math.c ft_str.c \
      solve_max.c solve_min.c \
      grid.c dupe.c \
      check.c brute.c 
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
