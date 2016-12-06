/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 12:39:21 by aphan             #+#    #+#             */
/*   Updated: 2016/11/04 14:17:30 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put0x(void)
{
	write(1, "0x", 2);
	return (1);
}

int			pf_p(t_pmod *p, va_list ap)
{
	uintmax_t	a;
	int			space;
	int			len;
	int			plen;

	p->base = 16;
	a = va_arg(ap, uintmax_t);
	len = pf_unbrlen(a, p->base);
	p->width -= 2;
	if (len == -1)
		return (-1);
	if ((p->flag % 5) && !(p->flag % 3) && p->prec < 0 && p->width > 0)
		p->prec = p->width;
	plen = (p->prec > len || (!(p->prec) && !a)) ? p->prec : len;
	(!(p->flag % 5) && put0x()) ? pf_putunbr(a, p, len) : 0;
	space = 0;
	plen = pf_putspace(plen, p) + 2;
	((p->flag % 5) && put0x()) ? pf_putunbr(a, p, len) : 0;
	return ((plen > p->width) ? plen : p->width);
}
