/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sanitize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:42:38 by prigaudi          #+#    #+#             */
/*   Updated: 2024/09/28 19:15:49 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen_sani(char *str)
{
	int	i;
	int	length;

	length = 0;
	i = 0;
	while (str[i] != ' ')
	{
		if (str[i] != ' ')
			length++;
		i++;
	}
	return (length);
}

char	*ft_sanitize(char	*str)
{
	int		i;
	int		j;
	int		length;
	char	*str_s;

	length = ft_strlen_sani(str);
	str_s = malloc(sizeof(char) * length + 1);
	if (str_s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			str_s[j] = str[i];
			j++;
		}
		i++;
	}
	str_s[j] = '\0';
	return (str_s);
}
