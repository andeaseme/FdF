/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 19:34:18 by aphan             #+#    #+#             */
/*   Updated: 2016/11/06 15:49:04 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put0(int hash)
{
	if (hash)
		write(1, "0", 1);
	return (1);
}

int			pf_o(t_pmod *p, va_list ap)
{
	uintmax_t	a;
	int			hash;
	int			len;
	int			plen;

	p->base = 8;
	if (p->spec == 7)
		p->length = 3;
	a = pf_u_cast(ap, p->length, p->base, &len);
	if (len == -1)
		return (-1);
	hash = (!(p->flag % 2) && (a || (!a && p->prec == 0)) && (p->prec <= len))
		? 1 : 0;
	if (hash)
		p->width -= 1;
	if ((p->flag % 5) && !(p->flag % 3) && p->prec < 0 && p->width > 0)
		p->prec = p->width;
	plen = (p->prec > len || (!(p->prec) && !a)) ? p->prec : len;
	(!(p->flag % 5) && put0(hash)) ? pf_putunbr(a, p, len) : 0;
	plen = pf_putspace(plen, p) + hash;
	((p->flag % 5) && put0(hash)) ? pf_putunbr(a, p, len) : 0;
	return ((plen > p->width) ? plen : p->width);
}
