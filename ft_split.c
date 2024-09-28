/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:20:27 by prigaudi          #+#    #+#             */
/*   Updated: 2024/09/28 13:41:07 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	count_words(char *str)
{
	int	sum;
	int	i;	

	sum = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] > 32 && str[i] < 127)
		{
			if (str[i + 1] == ' ')
				sum++;
			if (str[i + 1] == '\0')
				return (sum + 1);
		}
		i++;
	}
	return (sum);
}

char	*save_word(char **tab, char *str, int *end, int c)
{
	int	i;

	tab[c] = malloc(sizeof(char) * (end[1] - end[0] + 2));
	if (tab[c] == NULL)
		return (NULL);
	i = 0;
	while (i <= end[1] - end[0] + 1)
	{
		tab[c][i] = str[end[0] + i];
		i++;
	}
	tab[c][i] = '\0';
	return (tab[c]);
}

char	**ft_split(char *str, char *charset)
{
	int		nbr;
	int		i;
	int		limit[2];
	char	**result;	
	int		c;

	c = 0;
	nbr = count_words(str);
	result = malloc(sizeof(char *) * nbr + 1);
	if (result == NULL)
		return (result);
	i = -1;
	while (str[++i])
	{
		if (str[i] > 32 && str[i] < 127)
		{
			limit[0] = i;
			while (str[++i] > 32 && str[i] < 127)
			{
				if (str[i + 1] == ' ' || str[i + 1] == '\0')
				{
					limit[1] = i;
					save_word(result, str, limit, c);
					c++;
				}
			}
		}
	}
	return (result);
}

int	main(void)
{
	char	*str;
	char	**test;
	int		i;	

	str = "        Bonjour comment ca      va chez toi?      ";
	test = ft_split(str, " ");
	printf("Word count = %d\n", count_words(str));
	i = 0;
	while (i < 6)
	{
		printf("%s\n", test[i]);
		i++;
	}
}
