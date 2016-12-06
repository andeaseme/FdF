/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 10:06:14 by aphan             #+#    #+#             */
/*   Updated: 2016/09/23 23:30:46 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	int		i;
	int		mod;
	char	revstr[10];

	i = 0;
	if (nb >= -2147483648 && nb <= 2147483647)
	{
		if (nb < 0)
			ft_putchar('-');
		if (nb == 0)
			ft_putchar('0');
		while (nb != 0)
		{
			mod = nb % 10;
			if (mod < 0)
				mod *= -1;
			revstr[i] = mod;
			nb /= 10;
			i++;
		}
		while (--i != -1)
			ft_putchar(revstr[i] + '0');
	}
}
