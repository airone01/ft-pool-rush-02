# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elagouch <elagouch@42>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/28 10:51:47 by elagouch          #+#    #+#              #
#    Updated: 2024/09/29 10:11:55 by elagouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG = rush-02
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = main.c	\
      ft_atoi.c		\
      ft_itoa.c		\
      ft_join.c		\
      ft_putstr.c	\
      ft_split.c	\
      ft_strcat.c	\
      ft_strlen.c	\
      ft_strnew.c	\
      count_words	\
      find_word.c
INCL = rush.h
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
	rm -f a.out
re: fclean all
test-split: fclean
	$(CC) $(CFLAGS) tests/split.c *.c -o a.out
	# war split
test-putnbr: fclean
	$(CC) $(CFLAGS) main.c ft_itoa.c ft_putstr.c find_word.c putnbr_lang.c ft_strnew.c -o putnbr_lang
	# $(CC) $(CFLAGS) -I $(INCL) *.c -o putnbr_lang

.PHONY: all fclean re
