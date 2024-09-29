# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elagouch <elagouch@42>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/28 10:51:47 by elagouch          #+#    #+#              #
#    Updated: 2024/09/29 22:16:45 by prigaudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG = rush-01
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
SRC = main.c	\
      ft_atoi.c		\
      ft_check_charset.c	\
      ft_itoa.c		\
      ft_join.c		\
      ft_pow.c		\
      ft_putstr.c	\
      ft_split.c	\
      ft_strcat.c	\
      ft_strcmp.c	\
      ft_strdup.c	\
      ft_strlen.c	\
      ft_strnew.c	\
      count_words.c	\
      find_word.c	\
      putnbr_lang.c
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
