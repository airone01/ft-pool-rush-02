/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:09:59 by prigaudi          #+#    #+#             */
/*   Updated: 2024/09/16 07:25:38 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_recurs(char *s1, char *s2, int i)
{
	if (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i])
		{
			return (ft_recurs(s1, s2, i + 1));
		}
		else
		{
			return (s1[i] - s2[i]);
		}
	}
	else
	{
		return (s1[i] - s2[i]);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	return (ft_recurs(s1, s2, i));
}

/*int	main(void)
{
	char	*s1 = "AJ";
	char	*s2 = "AJR";

	ft_strcmp(s1, s2);
	printf("result = %d", ft_strcmp(s1, s2));
	printf("solution = %d", strcmp(s1, s2));
}*/
