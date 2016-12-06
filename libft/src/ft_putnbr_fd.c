/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 23:37:40 by aphan             #+#    #+#             */
/*   Updated: 2016/09/23 23:38:57 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int		i;
	int		mod;
	char	revstr[10];

	i = 0;
	if (nb >= -2147483648 && nb <= 2147483647)
	{
		if (nb < 0)
			ft_putchar_fd('-', fd);
		if (nb == 0)
			ft_putchar_fd('0', fd);
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
			ft_putchar_fd(revstr[i] + '0', fd);
	}
}
