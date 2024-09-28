/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:13:44 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/28 17:27:34 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# define CUBE_LEN 41

# include <stdlib.h>
# include <unistd.h>

// Strings <-> numbers
long	ft_atoi(char *str);
// STDIN manipulations
void	ft_putstr(char *str);
// Strings manipulation
char	**ft_split(char *str, char *charset);
char	*ft_strjoin(int size, char **strs, char *sep);
char	*ft_strcat(char *dest, char *src);
int	ft_strcmp(char *s1, char *s2)
int	ft_strlen(char *str);
int	count_words(char *str);
// Numbers manipulation
int	ft_pow(int nb, int pow);

#endif
