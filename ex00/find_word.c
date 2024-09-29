/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:11:51 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/29 21:33:47 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

#include <stdio.h>

/*
 * Finds the word in the cube corresponding to the searched number.
 * The cube being the following:
 *
 * `x`: lines
 * `y`: the two strings (left and right) for each line
 * 	(`to_find` being the left-side string and the
 * 	"word" being the righ-side one)
 * `z`: (disregard) the chars for each string
 *
 * ```
 *     #---y---#
 *    /|      /|
 *   z x     z x
 *  /  |    /  |
 * #===y===#---#
 * |  /    |  /
 * x z     x z
 * |/      |/
 * #===y===#
 * ```
 *
 * Args:
 * `cube`:	the "cube" mentionned above
 * `len`:	length of the cube on th x axis
 * `u`:		"unit"		(times of `qty`)
 * `qty`:	"quantity"	(power of thousands)
 *
 * Returns:
 * - the word corresponding to what we search for
 * - if not found, `NULL`
 * - if `ft_itoa` failed, `NULL`
 */
char	*find_word(char ***cube, int len, int u, int qty)
{
	int		i;
	char	*a_to_find;
	char	*head;

	head = ft_itoa(u);
	a_to_find = ft_strnew(1 + ft_strlen(head) + (3 * qty));
	ft_strcat(a_to_find, head);
	i = 0;
	while (i < qty)
	{
		ft_strcat(a_to_find, "000");
		i++;
	}
	// printf("\na_to_find='%s' for u='%d' and qty='%d'\n", a_to_find, u, qty);
	i = 0;
	while (i < len)
	{
		if (ft_strcmp(cube[i][0], a_to_find) == 0)
		{
			free(a_to_find);
			return (cube[i][1]);
		}
		i++;
	}
	free(a_to_find);
	return (NULL);
}
