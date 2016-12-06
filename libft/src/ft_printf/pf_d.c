/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 13:08:10 by aphan             #+#    #+#             */
/*   Updated: 2016/11/12 16:19:59 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		putsign(intmax_t nb, int flag)
{
	int		sign;

	sign = (nb < 0) ? 1 : 0;
	if (sign)
		ft_putchar('-');
	else if (!(flag % 7) && sign == 0 && ++sign)
		ft_putchar('+');
	else if (!(flag % 11) && sign == 0 && ++sign)
		ft_putchar(' ');
	return (sign);
}

int				pf_nbrlen(intmax_t value, const int base)
{
	int		len;

	len = 1;
	while (value /= base)
		len++;
	return (len);
}

void			pf_putnbr(intmax_t nb, t_pmod *p, int len)
{
	int			i;
	intmax_t	v;
	char		rstr[len + 1];
	int			sign;
	int			zero;

	i = 0;
	sign = putsign(nb, p->flag);
	if (nb == 0 && p->prec != 0)
		ft_putchar('0');
	zero = ((p->flag % 5) && p->prec < 0 && !(p->flag % 3) && p->width > 0)
		? (p->width - sign) : p->prec;
	while (zero > (len + i++))
		ft_putchar('0');
	i = 0;
	while (nb != 0)
	{
		v = (nb < 0) ? -(nb % p->base) : nb % p->base;
		rstr[i] = (v > 9) ? v + 'A' - 10 : v + '0';
		nb /= p->base;
		i++;
	}
	while (--i != -1)
		ft_putchar(rstr[i]);
}

static intmax_t	pf_d_cast(va_list ap, int length, int *len)
{
	intmax_t	a;

	*len = 0;
	a = 0;
	if (length == 1)
		a = va_arg(ap, int);
	else if (!(length % 13))
		a = va_arg(ap, long long int);
	else if (!(length % 3))
		a = va_arg(ap, long int);
	else if (!(length % 7))
		a = va_arg(ap, size_t);
	else if (!(length % 5))
		a = va_arg(ap, intmax_t);
	else if (!(length % 11))
		a = va_arg(ap, int);
	else if (!(length % 2))
		a = va_arg(ap, int);
	else
		*len = -1;
	if (*len != -1)
		*len = pf_nbrlen(a, 10);
	return (a);
}

int				pf_d(t_pmod *p, va_list ap)
{
	intmax_t	a;
	int			sign;
	int			len;
	int			plen;

	if (p->spec == 4)
		p->length = 3;
	a = pf_d_cast(ap, p->length, &len);
	if (len == -1)
		return (-1);
	sign = (a < 0 || !(p->flag % 7) || !(p->flag % 11)) ? 1 : 0;
	if ((p->flag % 5) && !(p->flag % 3) && p->prec < 0 && p->width > 0)
		p->prec = p->width - sign;
	plen = (p->prec > len || (!(p->prec) && !a)) ? p->prec : len;
	(!(p->flag % 5)) ? pf_putnbr(a, p, len) : 0;
	plen = pf_putspace(plen + sign, p);
	((p->flag % 5)) ? pf_putnbr(a, p, len) : 0;
	return ((plen > p->width) ? plen : p->width);
}
