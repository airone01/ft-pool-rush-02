/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prigaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:53:57 by prigaudi          #+#    #+#             */
/*   Updated: 2024/09/29 15:07:51 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_split.c"
#include "ft_strcmp.c"

char    **ft_split(char *str, char *charset);
int		ft_strcmp(char *s1, char *s2);

char	***extract_data(void)
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
		i++;
	}
	return (dico2);
}	

int	nb_cmp(char	a, char b)
{
	if (a == b)
		return (1);
	return (0);
}

void	put_str(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}	

void	str_trad(char *str, char ***dico2)
{
	int str_len;
	int	i;
odify	int j;

	str_len = 0;
	while (str[str_len] != '\0')
		str_len++;
	i = str_len - 1;
	while (i > 0)
	{
		j = 0
		while (j <= 41)
		{
			if (nb_cmp(str[i], dico2[j][0][0]) == 1)
			{
				put_str(dico2[j][1]);
				break;
			}
			j++;
		}	
		i++;
	}	
}

int	main(int argc, char **argv)
{
	char	***dico2;

	dico2 = extract_data();
	str_trad(argv[1], dico2);
}
