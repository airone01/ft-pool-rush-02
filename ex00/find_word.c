/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:11:51 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/29 11:16:35 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

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
	int		to_find;
	int		i;
	char	*a_to_find;

	to_find = u * ft_pow(1000, qty);
	a_to_find = ft_itoa(to_find);
	if (a_to_find == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (ft_strcmp(cube[i][0], a_to_find) == 0)
			return (cube[i][1]);
		i++;
	}
	free(a_to_find);
	return (NULL);
}
