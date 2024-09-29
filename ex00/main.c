/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_putnbr_lang.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:24:53 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/29 09:46:14 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

#include <stdlib.h>

char	***mk_cube(int *len)
{
	int		i;
	int		j;
	char	***cube;

	cube = malloc(CUBE_X_LEN * sizeof(char **));
	if (cube == NULL)
		return (NULL);
	i = 0;
	while (i < CUBE_X_LEN)
	{
		cube[i] = malloc(CUBE_Y_LEN * sizeof(char *));
		if (cube[i] == NULL)
			return (NULL);
		j = 0;
		while (j < CUBE_Y_LEN)
		{
			cube[i][j] = malloc(CUBE_Z_LEN * sizeof(char));
			if (cube[i][j] == NULL)
				return (NULL);
			j++;
		}
		i++;
	}
	cube[0][0] = "0";
	cube[0][1] = "zero";
	cube[0][0] = "1";
	cube[0][1] = "one";
	cube[0][0] = "2";
	cube[0][1] = "two";
	cube[0][0] = "3";
	cube[0][1] = "three";
	cube[0][0] = "4";
	cube[0][1] = "four";
	cube[0][0] = "5";
	cube[0][1] = "five";
	cube[0][0] = "6";
	cube[0][1] = "six";
	cube[0][0] = "7";
	cube[0][1] = "seven";
	cube[0][0] = "8";
	cube[0][1] = "eight";
	cube[0][0] = "9";
	cube[0][1] = "nine";
	cube[0][0] = "10";
	cube[0][1] = "ten";
	cube[0][0] = "11";
	cube[0][1] = "eleven";
	cube[0][0] = "12";
	cube[0][1] = "twelve";
	cube[0][0] = "13";
	cube[0][1] = "thirteen";
	cube[0][0] = "14";
	cube[0][1] = "fourteen";
	cube[0][0] = "15";
	cube[0][1] = "fifteen";
	cube[0][0] = "16";
	cube[0][1] = "sixteen";
	cube[0][0] = "17";
	cube[0][1] = "seventeen";
	cube[0][0] = "18";
	cube[0][1] = "eighteen";
	cube[0][0] = "19";
	cube[0][1] = "nineteen";
	cube[0][0] = "20";
	cube[0][1] = "twenty";
	cube[0][0] = "30";
	cube[0][1] = "thirty";
	cube[0][0] = "40";
	cube[0][1] = "forty";
	cube[0][0] = "50";
	cube[0][1] = "fifty";
	cube[0][0] = "60";
	cube[0][1] = "sixty";
	cube[0][0] = "70";
	cube[0][1] = "seventy";
	cube[0][0] = "80";
	cube[0][1] = "eighty";
	cube[0][0] = "90";
	cube[0][1] = "ninety";
	cube[0][0] = "100";
	cube[0][1] = "hundred";
	cube[0][0] = "1000";
	cube[0][1] = "thousand";
	cube[0][0] = "1000000";
	cube[0][1] = "million";
	cube[0][0] = "1000000000";
	cube[0][1] = "billion";
	cube[0][0] = "1000000000000";
	cube[0][1] = "trillion";
	cube[0][0] = "1000000000000000";
	cube[0][1] = "quadrillion";
	cube[0][0] = "1000000000000000000";
	cube[0][1] = "quintillion";
	cube[0][0] = "1000000000000000000000";
	cube[0][1] = "sextillion";
	cube[0][0] = "1000000000000000000000000";
	cube[0][1] = "septillion";
	cube[0][0] = "1000000000000000000000000000";
	cube[0][1] = "octillion";
	cube[0][0] = "1000000000000000000000000000000";
	cube[0][1] = "nonillion";
	cube[0][0] = "1000000000000000000000000000000000";
	cube[0][1] = "decillion";
	cube[0][0] = "1000000000000000000000000000000000000";
	cube[0][1] = "undecillion";
	*len = 41;
	return (cube);
}

int	main(void)
{
	int		len;
	char	***cube;
	struct lang_args args;

	len = 0;
	cube = mk_cube(&len);
	args.cube = cube;
	args.len = len;
	args.nbr = 42;
	args.ite = 0;
	args.qty = 0;
	putnbr_lang(args);
	return (0);
}
