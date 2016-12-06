/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 21:54:23 by aphan             #+#    #+#             */
/*   Updated: 2016/09/25 22:04:26 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ap_putnbr_hex(int octet, int rem)
{
	const char *base = "0123456789abcdef";

	while (rem > 1)
	{
		ap_putnbr_hex((octet >> 4), rem - 1);
		rem /= 2;
	}
	write(1, base + (octet % 16), 1);
}

static void	ap_putchar_hex(const unsigned char *addr)
{
	const unsigned char c = *addr;

	if (c >= ' ' && c <= '~')
		write(1, &c, 1);
	else
		write(1, ".", 1);
}

static void	ap_print_number(const unsigned char *addr, size_t size, size_t i)
{
	size_t a;

	a = 0;
	while (a < 16 && a + i < size)
	{
		ap_putnbr_hex(*(addr + a + i), 2);
		if (a % 2)
			write(1, " ", 1);
		a++;
	}
	while (a < 16)
	{
		write(1, "  ", 2);
		if (a % 2)
			write(1, " ", 1);
		a++;
	}
}

static void	ap_print_character(const unsigned char *addr, size_t size, size_t i)
{
	size_t a;

	a = 0;
	while (a < 16 && a + i < size)
	{
		ap_putchar_hex(addr + a + i);
		a++;
	}
}

void		ft_print_memory(const void *addr, size_t size)
{
	size_t index;

	index = 0;
	while (index < size)
	{
		ap_print_number((const unsigned char *)addr, size, index);
		ap_print_character((const unsigned char *)addr, size, index);
		write(1, "\n", 1);
		index += 16;
	}
}
