/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ismodifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:19:29 by aphan             #+#    #+#             */
/*   Updated: 2016/11/05 11:57:00 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_isspec(int a)
{
	char	*specifier;

	if (!a)
		return (-1);
	specifier = SPEC;
	return (ft_strchr(specifier, a) - specifier);
}

int		pf_isflag(int a)
{
	if (a == '#' || a == '0' || a == '-' || a == '+' || a == ' ')
		return (1);
	return (0);
}

int		pf_islength(int a)
{
	if (a == 'h' || a == 'l' || a == 'j' || a == 'z')
		return (1);
	return (0);
}

int		pf_putspace(int plen, t_pmod *p)
{
	if (!((p->flag % 5) && p->prec < 0 && !(p->flag % 3) && p->width > 0))
		while ((p->width > plen))
		{
			ft_putchar(' ');
			plen++;
		}
	return (plen);
}
