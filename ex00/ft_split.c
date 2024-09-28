/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:20:27 by prigaudi          #+#    #+#             */
/*   Updated: 2024/09/28 17:09:40 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*save_word(char **tab, char *str, int *limit, int c)
{
	int	i;

	tab[c] = malloc(sizeof(char) * (limit[1] - limit[0] + 2));
	if (tab[c] == NULL)
		return (NULL);
	i = 0;
	while (i <= limit[1] - limit[0] + 1)
	{
		tab[c][i] = str[limit[0] + i];
		i++;
	}
	tab[c][i] = '\0';
	return (tab[c]);
}

char	**ft_split(char *str, char *charset)
{
	int		limit[2];
	int		nbr;
	int		i;
	int		c;
	char	**result;	

	c = 0;
	nbr = count_words(str, charset);
	result = malloc(sizeof(char *) * nbr + 1);
	if (result == NULL)
		return (result);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] < 127 && str[i] != charset[0])
		{
			limit[0] = i;
			while (str[i] >= 32 && str[i] < 127 && str[i] != charset[0])
			{
				if (str[i + 1] == charset[0] || str[i + 1] == '\0')
				{
					limit[1] = i - 1;
					save_word(result, str, limit, c);
					c++;
				}
				i++;
			}
		}
		i++;
	}
	result[c] = NULL; 
	return (result);
}
