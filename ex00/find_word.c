/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:11:51 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/28 17:35:47 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

/*
 * Finds the word in the cube corresponding to the searched number.
 *
 * u:	"unit"		(times of qty)
 * qty:	"quantity"	(power of thousands)
 *
 * In:
 * to_find = u * (1000^qty)
 *
 * Returns:
 * - the word corresponding to what we search for
 * - if not found, NULL
 */
char	*find_word(char ***cube, int u, int qty)
{
	int	to_find;
	int	a_to_find;
	int	i;

	to_find = u * ft_pow(1000, qty);
	a_to_find = itoa(to_find);
	i = 0;
	while (i < CUBE_LEN)
	{
		if (str_cmp(cube[i][0], a_to_find) == 0)
			return (cube[i][1]);
		i++;
	}
	return (NULL);
}
