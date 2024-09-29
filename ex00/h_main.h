/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_main.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:13:44 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/29 23:06:20 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
#define RUSH_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// Rush-specific
char	*find_word(char ***cube, int len, int u, int qty);
struct lang_args {
	char ***cube;
	char *nbr;
	int len;
	int ite;
	int qty;
};

#include "h_str.h"
#include "h_putnbr_lang.h"

#endif
