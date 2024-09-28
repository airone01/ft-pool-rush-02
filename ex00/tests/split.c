/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:20:27 by prigaudi          #+#    #+#             */
/*   Updated: 2024/09/28 14:08:21 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rush.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	int		i;	
	char	**test;

	(void) argc;
	test = ft_split(argv[1], argv[2]);
	printf("%d", count_words(argv[1]));
	i = 0;
	while (i < 6)
	{
		printf("%s|", test[i]);
		i++;
	}
}
