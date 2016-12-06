/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 18:01:04 by aphan             #+#    #+#             */
/*   Updated: 2016/11/05 11:16:53 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putx(int hash, int spec, int value)
{
	if (spec == 11 && hash && value)
		write(1, "0X", 2);
	else if (hash && value)
		write(1, "0x", 2);
	return (1);
}

int			pf_x(t_pmod *p, va_list ap)
{
	uintmax_t	a;
	int			hash;
	int			len;
	int			plen;

	p->base = 16;
	a = pf_u_cast(ap, p->length, p->base, &len);
	if (len == -1)
		return (-1);
	hash = (!(p->flag % 2) && a) ? 2 : 0;
	if (hash)
		p->width -= 2;
	if ((p->flag % 5) && !(p->flag % 3) && p->prec < 0 && p->width > 0)
		p->prec = p->width;
	plen = (p->prec > len || (!(p->prec) && !a)) ? p->prec : len;
	(!(p->flag % 5) && putx(hash, p->spec, a)) ? pf_putunbr(a, p, len) : 0;
	plen = pf_putspace(plen, p) + hash;
	((p->flag % 5) && putx(hash, p->spec, a)) ? pf_putunbr(a, p, len) : 0;
	return ((plen > p->width) ? plen : p->width);
}
