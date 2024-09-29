/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_lang.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:13:33 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/29 22:41:27 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	putnbr_lang_3x(struct lang_args args, int three_x);
void	putnbr_lang_3x_hundreds(struct lang_args args, int three_x);
void	putnbr_lang_3x_tens(struct lang_args args, int three_x);
void	putnbr_lang_3x_tens(struct lang_args args, int three_x);
void	putnbr_lang_3x_units(struct lang_args args, int three_x);
void	putnbr_lang_3x_specials(struct lang_args args, int three_x);
void	putnbr_lang_3x_qty(struct lang_args args, int three_x);

/*
 * Gets a 3x int number from the full string number.
 *
 * It copies the left-side of the string first, and
 * then slides to the right to keep a 3x if needed.
 *
 * @param	args	structure that contains the following:
 * @param	cube	see comment in `find_word.c`
 * @param	nbr		the full number to print
 * @param	ite		the current iteration. Starts at 0.
 */
int	get_3x(struct lang_args args)
{
	char	*dest;
	char	*dest2;
	int		nbr_len;
	int		diff;
	int		i;

	nbr_len = ft_strlen(args.nbr);
	dest = ft_strnew(nbr_len + 3);
	ft_strcpy(dest, args.nbr);
	if (nbr_len % 3 != 0)
	{
		diff = nbr_len % 3;
		free(dest);
		dest = ft_strnew(nbr_len + diff + 1);
		i = 0;
		while (i < 3 - diff)
		{
			dest[i++] = '0';
		}
		ft_strcat(dest, args.nbr);
		// printf("\ndest: '%s'\n", dest);
	}
	dest2 = ft_strnew(nbr_len + 3);
	ft_strncpy(dest2, dest, (args.ite + 1) * 3);
	dest2 += args.ite * 3;
	//
	// free(dest);
	// printf("dest2: '%s'\n", dest2);
	// printf("b4 atoi: '%s'\nOG nbr: '%s'\n", dest, args.nbr);
	return (atoi(dest2));
}

/*
 * Recursively puts the plain-language words
 * that correspond to the number to STDOUT.
 *
 * @param	args	structure that contains the following:
 * @param	cube	see comment in `find_word.c`
 * @param	nbr		the full number to print
 * @param	ite		the current iteration. Starts at 0.
 */
void	putnbr_lang(struct lang_args args)
{
	struct lang_args	args_fake;
	struct lang_args	args_new;
	int					three_x;

	if (args.qty < 0)
		return ;
	three_x = get_3x(args);
	// args_fake.nbr = (args.nbr / ft_pow(1000, args.qty)) % 1000;
	//		gives us the 3x of the current number compared
	//		to the qty.
	// printf("\n3x: %d\n", three_x);
	if (args.qty >= 1)
	{
		args_fake = args;
		args_new = args;
		args_new.ite = args.ite + 1;
		args_new.qty = args.qty - 1;
		putnbr_lang_3x(args_fake, three_x);
		putnbr_lang_3x_qty(args_fake, three_x);
		putnbr_lang(args_new);
		return ;
	}
	putnbr_lang_3x(args, three_x);
}

/*
 * Puts a group of three digits ("3x").
 */
void	putnbr_lang_3x(struct lang_args args, int three_x)
{
	putnbr_lang_3x_hundreds(args, three_x);
	if ((three_x % 100) >= 11 && (three_x % 100) <= 19)
		putnbr_lang_3x_specials(args, three_x);
	else
	{
		putnbr_lang_3x_tens(args, three_x);
		putnbr_lang_3x_units(args, three_x);
	}
}

/*
 * Puts the hundreds of a 3x
 */
void	putnbr_lang_3x_hundreds(struct lang_args args, int three_x)
{
	int	hundreds;

	hundreds = three_x / 100;
	if (hundreds <= 0)
		return ;
	if (args.ite != 0)
		ft_putstr(" ");
	ft_putstr(find_word(args.cube, args.len, hundreds, 0));
	ft_putstr(" hundred");
}

/*
 * Puts the tens of a 3x
 */
void	putnbr_lang_3x_tens(struct lang_args args, int three_x)
{
	int	tens;

	tens = (three_x / 10) % 10;
	if (tens <= 0)
		return ;
	if (three_x / 100 > 0)
		ft_putstr(" ");
	ft_putstr(find_word(args.cube, args.len, tens * 10, 0));
}

/*
 * Puts the units of a 3x
 */
void	putnbr_lang_3x_units(struct lang_args args, int three_x)
{
	int	units;

	units = three_x % 10;
	if (units <= 0)
		return ;
	if ((three_x / 10) % 10 > 0)
		ft_putstr("-");
	else if (args.ite != 0)
		ft_putstr(" ");
	ft_putstr(find_word(args.cube, args.len, units, 0));
}

/*
 * Puts "special" numbers of a 3x.
 * "special" numbers are the ones between 11 and 19 included.
 */
void	putnbr_lang_3x_specials(struct lang_args args, int three_x)
{
	int	specials;

	specials = three_x % 100;
	if (args.ite != 0)
		ft_putstr(" ");
	ft_putstr(find_word(args.cube, args.len, specials, 0));
}

/*
 * Puts the `qty` ("thousand", "million", "billion", etc...).
 */
void	putnbr_lang_3x_qty(struct lang_args args, int three_x)
{
	// printf("\nqty_3x: %d\n", three_x);
	(void) three_x;
	if (three_x > 0)
	{
		ft_putstr(" ");
		ft_putstr(find_word(args.cube, args.len, 1, args.qty));
	}
	args.ite++;
	args.qty--;
	if (get_3x(args) != 0)
		ft_putstr(" and");
}
