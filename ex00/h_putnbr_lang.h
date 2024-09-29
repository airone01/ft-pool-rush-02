/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_putnbr_lang.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 22:45:53 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/29 23:08:06 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_PUTNBR_LANG_H
#define RUSH_PUTNBR_LANG_H

// QTY
void	putnbr_lang_3x_hundreds(struct lang_args args, int three_x);
void	putnbr_lang_3x_tens(struct lang_args args, int three_x);
void	putnbr_lang_3x_units(struct lang_args args, int three_x);
// Extra
void	putnbr_lang_3x_specials(struct lang_args args, int three_x);
void	putnbr_lang_3x_qty(struct lang_args args, int three_x);
// Final form
void	putnbr_lang(struct lang_args args);
int	get_3x(struct lang_args args);

#endif
