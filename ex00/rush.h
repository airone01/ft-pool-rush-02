/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:13:44 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/28 11:24:49 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

// Strings <-> numbers
long	ft_atoi(char *str)
// STDIN manipulations
void	ft_putstr(char *str)
// Strings manipulation
char	*ft_strjoin(int size, char **strs, char *sep);
char	*ft_strcat(char *dest, char *src)
int	ft_strlen(char *str)

#endif
