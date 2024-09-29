/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:13:44 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/29 19:46:19 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
#define RUSH_H

#include <stdlib.h>
#include <unistd.h>

#define CUBE_X_LEN 41
#define CUBE_Y_LEN 2
#define CUBE_Z_LEN 50

// Strings <-> numbers
char	*ft_itoa(int nb);
long	ft_atoi(char *str);
// STDIN manipulations
void	ft_putstr(char *str);
// Strings manipulation
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
char	**ft_split(char *str, char *charset);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strjoin(int size, char **strs, char *sep);
char	*ft_strcat(char *dest, char *src);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *src);
char	*ft_strnew(int size);
int	ft_strcmp(char *s1, char *s2);
int	ft_strlen(char *str);
int	count_words(char *str, char *charset);
// Numbers manipulation
int	ft_pow(int nb, int power);
// Rush-specific
char	*find_word(char ***cube, int len, int u, int qty);
struct lang_args {
	char ***cube;
	char *nbr;
	int len;
	int ite;
	int qty;
};
void	putnbr_lang(struct lang_args args);

#endif
