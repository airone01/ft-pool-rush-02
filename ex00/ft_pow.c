/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@42>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:43:52 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/28 17:51:15 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Calculates `nb` to the power of `power`
 *
 * Returns:
 * - The result
 * - If `power` lower than 0, 0.
 */
int	ft_pow(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (ft_pow(nb, power - 1) * nb);
}
