/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:11:51 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/28 17:51:22 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

/*
 * Finds the word in the cube corresponding to the searched number.
 *
 * `u`:		"unit"		(times of `qty`)
 * `qty`:	"quantity"	(power of thousands)
 *
 * In:
 * ```c
 * to_find = u * pow(1000, qty);
 * ```
 *
 * Returns:
 * - the word corresponding to what we search for
 * - if not found, `NULL`
 * - if `ft_itoa` failed, `NULL`
 */
char	*find_word(char ***cube, int u, int qty)
{
	int		to_find;
	int		i;
	char	*a_to_find;

	to_find = u * ft_pow(1000, qty);
	a_to_find = ft_itoa(to_find);
	if (a_to_find == NULL)
		return (NULL);
	i = 0;
	while (i < CUBE_LEN)
	{
		if (str_cmp(cube[i][0], a_to_find) == 0)
			return (cube[i][1]);
		i++;
	}
	free(a_to_find);
	return (NULL);
}
