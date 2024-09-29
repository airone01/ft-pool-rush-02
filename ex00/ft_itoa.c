/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:41:30 by gaducurt          #+#    #+#             */
/*   Updated: 2024/09/28 18:19:58 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int nb, char *key, int i)
{
	if (nb < 0)
	{
		key[i] = '-';
		nb = -nb;
		i++;
	}
	if (nb < 9 && nb >= 0)
	{
		key[i] = nb - '0';
		key[i + 1] = '\0';
	}
	if (nb > 9)
	{
		(ft_itoa((nb / 10), key, i + 1));
		key[i] = (nb % 10) - '0';
	}
	return (key);
}

char	*init_str(int nb)
{
	char	*key;
	int	i;
	int	temp;
	
	if (nb < 0)
	{
		i = 2;
		temp = -nb;
	}
	else
	{
		i = 1;
		temp = nb;
	}
	while (temp > 9)
	{
		i++;
		temp = temp / 10;
	}
	key = malloc(i + 1 * sizeof(char));
	if (!(key))
		return (0);
	return (ft_itoa(nb, key, 0));
}

int	main()
{
	int	nb = -12;
	int	i = 0;
	char *key = init_str(nb);

	while (key[i])
	{
		printf("%d", key[i]);
		i++;
	}
}
