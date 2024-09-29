/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:24:53 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/29 11:11:32 by elagouch         ###   ########.fr       */
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
	cube[1][0] = "1";
	cube[1][1] = "one";
	cube[2][0] = "2";
	cube[2][1] = "two";
	cube[3][0] = "3";
	cube[3][1] = "three";
	cube[4][0] = "4";
	cube[4][1] = "four";
	cube[5][0] = "5";
	cube[5][1] = "five";
	cube[6][0] = "6";
	cube[6][1] = "six";
	cube[7][0] = "7";
	cube[7][1] = "seven";
	cube[8][0] = "8";
	cube[8][1] = "eight";
	cube[9][0] = "9";
	cube[9][1] = "nine";
	cube[10][0] = "10";
	cube[10][1] = "ten";
	cube[11][0] = "11";
	cube[11][1] = "eleven";
	cube[12][0] = "12";
	cube[12][1] = "twelve";
	cube[13][0] = "13";
	cube[13][1] = "thirteen";
	cube[14][0] = "14";
	cube[14][1] = "fourteen";
	cube[15][0] = "15";
	cube[15][1] = "fifteen";
	cube[16][0] = "16";
	cube[16][1] = "sixteen";
	cube[17][0] = "17";
	cube[17][1] = "seventeen";
	cube[18][0] = "18";
	cube[18][1] = "eighteen";
	cube[19][0] = "19";
	cube[19][1] = "nineteen";
	cube[20][0] = "20";
	cube[20][1] = "twenty";
	cube[21][0] = "30";
	cube[21][1] = "thirty";
	cube[22][0] = "40";
	cube[22][1] = "forty";
	cube[23][0] = "50";
	cube[23][1] = "fifty";
	cube[24][0] = "60";
	cube[24][1] = "sixty";
	cube[25][0] = "70";
	cube[25][1] = "seventy";
	cube[26][0] = "80";
	cube[26][1] = "eighty";
	cube[27][0] = "90";
	cube[27][1] = "ninety";
	cube[28][0] = "100";
	cube[28][1] = "hundred";
	cube[29][0] = "1000";
	cube[29][1] = "thousand";
	cube[30][0] = "1000000";
	cube[30][1] = "million";
	cube[31][0] = "1000000000";
	cube[31][1] = "billion";
	cube[32][0] = "1000000000000";
	cube[32][1] = "trillion";
	cube[33][0] = "1000000000000000";
	cube[33][1] = "quadrillion";
	cube[34][0] = "1000000000000000000";
	cube[34][1] = "quintillion";
	cube[35][0] = "1000000000000000000000";
	cube[35][1] = "sextillion";
	cube[36][0] = "1000000000000000000000000";
	cube[36][1] = "septillion";
	cube[37][0] = "1000000000000000000000000000";
	cube[37][1] = "octillion";
	cube[38][0] = "1000000000000000000000000000000";
	cube[38][1] = "nonillion";
	cube[39][0] = "1000000000000000000000000000000000";
	cube[39][1] = "decillion";
	cube[40][0] = "1000000000000000000000000000000000000";
	cube[40][1] = "undecillion";
	*len = 41;
	return (cube);
}

void	del_cube(char ***cube, int len)
{
	int		i;
	int		j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < CUBE_Y_LEN)
		{
			free(cube[i][j]);
			j++;
		}
		free(cube[i]);
		i++;
	}
	free(cube);
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
	del_cube(cube, CUBE_X_LEN);
	return (0);
}
