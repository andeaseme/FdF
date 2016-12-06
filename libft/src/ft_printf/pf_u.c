/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 13:08:10 by aphan             #+#    #+#             */
/*   Updated: 2016/11/12 16:20:55 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_unbrlen(uintmax_t value, const int base)
{
	int		len;

	len = 1;
	while (value /= base)
		len++;
	return (len);
}

void		pf_putunbr(uintmax_t nb, t_pmod *p, int len)
{
	int			i;
	uintmax_t	v;
	char		rstr[len + 1];
	char		a;
	int			zero;

	i = 0;
	if (nb == 0 && (p->prec != 0))
		ft_putchar('0');
	zero = ((p->flag % 5) && p->prec < 0 && !(p->flag % 3) && p->width > 0)
		? p->width : p->prec;
	while (zero > (len + i++))
		ft_putchar('0');
	a = (p->spec == 11) ? 'A' : 'a';
	i = 0;
	while (nb != 0)
	{
		v = nb % p->base;
		rstr[i] = (v > 9) ? v + a - 10 : v + '0';
		nb /= p->base;
		i++;
	}
	while (--i != -1)
		ft_putchar(rstr[i]);
}

uintmax_t	pf_u_cast(va_list ap, int length, int base, int *len)
{
	uintmax_t	a;

	*len = 0;
	a = 0;
	if (length == 1)
		a = va_arg(ap, unsigned int);
	else if (!(length % 13))
		a = va_arg(ap, unsigned long long int);
	else if (!(length % 3))
		a = va_arg(ap, unsigned long int);
	else if (!(length % 7))
		a = va_arg(ap, size_t);
	else if (!(length % 5))
		a = va_arg(ap, uintmax_t);
	else if (!(length % 11))
		a = va_arg(ap, unsigned int);
	else if (!(length % 2))
		a = va_arg(ap, unsigned int);
	else
		*len = -1;
	if (*len != -1)
		*len = pf_unbrlen(a, base);
	return (a);
}

int			pf_u(t_pmod *p, va_list ap)
{
	uintmax_t	a;
	int			len;
	int			plen;

	if (p->spec == 9)
		p->length = 3;
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
