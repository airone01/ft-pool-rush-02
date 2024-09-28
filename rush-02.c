/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:53:57 by prigaudi          #+#    #+#             */
/*   Updated: 2024/09/28 16:19:56 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_split.c"

char    **ft_split(char *str, char *charset);

int	main(void)
{
	int		file;
	char	buffer[5000];
	char	**dico1;
	char	***dico2;
	int		i;
	int		len;

	file = open("./numbers.dict", O_RDONLY);
	read(file, buffer, 5000);
	dico1 = ft_split(buffer, "\n");
	len = 0;
	while (dico1[i++])
		len++;
	dico2 = malloc(sizeof(char **) * len);
	i = 0;
	while (dico1[i])
	{	
		dico2[i] = ft_split(dico1[i],":");
		printf("Key: '%s', Value: '%s'\n", dico2[i][0], dico2[i][1]);
		i++;
	}
}
