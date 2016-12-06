/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 13:08:10 by aphan             #+#    #+#             */
/*   Updated: 2016/11/09 17:16:10 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_b(t_pmod *p, va_list ap)
{
	uintmax_t	a;
	int			len;
	int			plen;

	p->base = 2;
	a = pf_u_cast(ap, p->length, p->base, &len);
	if (len == -1)
		return (-1);
	if ((p->flag % 5) && !(p->flag % 3) && p->prec == -1 && p->width > 0)
		p->prec = p->width;
	plen = (p->prec > len || (!(p->prec) && !a)) ? p->prec : len;
	(!(p->flag % 5)) ? pf_putunbr(a, p, len) : 0;
	plen = pf_putspace(plen, p);
	((p->flag % 5)) ? pf_putunbr(a, p, len) : 0;
	return ((plen > p->width) ? plen : p->width);
}

int		pf_n(t_pmod *p, va_list ap)
{
	intmax_t	*n;

	n = va_arg(ap, void *);
	*n = p->count;
	return (0);
}

int		pf_tint(t_pmod *p, va_list ap)
{
	(void)ap;
	write(1, "\x1B[", 3);
	ft_putnbr(p->width);
	write(1, "m", 1);
	return (0);
}
