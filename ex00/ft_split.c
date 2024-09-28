/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:20:27 by prigaudi          #+#    #+#             */
/*   Updated: 2024/09/28 14:58:15 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

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
	int		limit[2];
	int		nbr;
	int		i;
	int		c;
	char	**result;	

	c = 0;
	i = -1;
	(void) charset;
	nbr = count_words(str);
	result = malloc(sizeof(char *) * nbr + 1);
	if (result == NULL)
		return (result);
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
