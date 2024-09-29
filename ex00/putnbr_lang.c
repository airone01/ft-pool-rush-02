/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_lang.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:13:33 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/29 13:53:59 by prigaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

#include <stdio.h> // ATTENTION

void	putnbr_lang_3x(struct lang_args args);
void	putnbr_lang_3x_hundreds(struct lang_args args);
void	putnbr_lang_3x_tens(struct lang_args args);
void	putnbr_lang_3x_tens(struct lang_args args);
void	putnbr_lang_3x_units(struct lang_args args);
void	putnbr_lang_3x_specials(struct lang_args args);
void	putnbr_lang_3x_qty(struct lang_args args);

/*
 * Recursively puts the plain-language words
 * that correspond to the number to STDOUT.
 *
 * Args:
 * `cube`:	see comment in `find_word.c`
 * `nbr`:	the full number to print
 * `ite`:	the current iteration. Starts at 0.
 */
void	putnbr_lang(struct lang_args args)
{
	struct lang_args args_fake;
	struct lang_args args_new;

	if (args.qty < 0 || args.nbr < 0)
		return ;
	if (args.qty >= 1)
	{
		args_fake = args;
		args_fake.nbr = (args.nbr / ft_pow(1000, args.qty)) % 1000;
		//		gives us the 3x of the current number compared
		//		to the qty.
		args_new = args;
		args_new.ite = args.ite + 1;
		args_new.qty = args.qty - 1;
		putnbr_lang_3x(args_fake);
		putnbr_lang_3x_qty(args_fake);
		putnbr_lang(args_new);
		return ;
	}
	args.nbr = (args.nbr / ft_pow(1000, args.qty)) % 1000;
	putnbr_lang_3x(args);
}

/*
 * Puts a group of three digits ("3x").
 */
void	putnbr_lang_3x(struct lang_args args)
{
	// printf("3x: '%d'\n", args.nbr);
	//if (args.ite != 0)
	//	ft_putstr(" and");
	putnbr_lang_3x_hundreds(args);
	if ((args.nbr % 100) >= 11 && (args.nbr % 100) <= 19)
		putnbr_lang_3x_specials(args);
	else
	{
		putnbr_lang_3x_tens(args);
		putnbr_lang_3x_units(args);
	}
//	putnbr_lang_3x_qty(args);
}

/*
 * Puts the hundreds of a 3x
 */
void	putnbr_lang_3x_hundreds(struct lang_args args)
{
	int	hundreds;

	hundreds = args.nbr / 100;
	if (hundreds <= 0)
		return ;
	ft_putstr(" ");
	ft_putstr(find_word(args.cube, args.len, hundreds, 0));
	ft_putstr(" hundred");
}

/*
 * Puts the tens of a 3x
 */
void	putnbr_lang_3x_tens(struct lang_args args)
{
	int	tens;

	tens = (args.nbr / 10) % 10;
	if (tens <= 0)
		return ;
	if (args.nbr / 100 > 0)
		ft_putstr(" ");
	ft_putstr(find_word(args.cube, args.len, tens * 10, 0));
}

/*
 * Puts the units of a 3x
 */
void	putnbr_lang_3x_units(struct lang_args args)
{
	int	units;

	units = args.nbr % 10;
	if (units <= 0)
		return ;
	if ((args.nbr / 10) % 10 > 0)
		ft_putstr("-");
	else
		ft_putstr(" ");
	ft_putstr(find_word(args.cube, args.len, units, 0));
}

/*
 * Puts "special" numbers of a 3x.
 * "special" numbers are the ones between 11 and 19 included.
 */
void	putnbr_lang_3x_specials(struct lang_args args)
{
	int	specials;

	specials = args.nbr % 100;
	ft_putstr(" ");
	ft_putstr(find_word(args.cube, args.len, specials, 0));
}

/*
 * Puts the `qty` ("thousand", "million", "billion", etc...).
 */
void	putnbr_lang_3x_qty(struct lang_args args)
{
	if (args.nbr == 0 || args.qty <= 0)
		return;
	ft_putstr(" ");
	ft_putstr(find_word(args.cube, args.len, 1, args.qty));
}
