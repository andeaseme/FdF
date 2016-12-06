/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 12:54:44 by aphan             #+#    #+#             */
/*   Updated: 2016/11/06 14:52:09 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				pf_wctoc(wchar_t wc, char *c)
{
	int		i;

	i = 0;
	if (wc <= 0x0000007F && (i = 1))
		*c = (wc & 0x7F);
	else if (wc >= 0x00000080 && wc <= 0x000007FF && (i = 2))
	{
		*(c + 1) = (wc & 0x3F) | 0x80;
		*c = ((wc >> 6) & 0x1F) | 0xC0;
	}
	else if (wc >= 0x00000800 && wc <= 0x0000FFFF && (i = 3))
	{
		*(c + 2) = (wc & 0x3F) | 0x80;
		*(c + 1) = ((wc >> 6) & 0x3F) | 0x80;
		*c = ((wc >> 12) & 0x0F) | 0xE0;
	}
	else if (wc >= 0x00010000 && wc <= 0x001FFFFF && (i = 4))
	{
		*(c + 3) = (wc & 0x3F) | 0x80;
		*(c + 2) = ((wc >> 6) & 0x3F) | 0x80;
		*(c + 1) = ((wc >> 12) & 0x3F) | 0x80;
		*c = ((wc >> 18) & 0x07) | 0xF0;
	}
	*(c + i) = 0;
	return (i);
}

static void		*pf_wstos(wchar_t *wstr, int *clen)
{
	char	*c;
	int		i;
	int		len;

	*clen = 0;
	len = 0;
	c = NULL;
	if (wstr)
	{
		while (wstr[len])
			len++;
		if (!(c = ft_strnew(sizeof(wchar_t) * len + 1)))
			return (0);
		i = 0;
		while (i < len)
		{
			*clen += pf_wctoc(wstr[i], (c + *clen));
			i++;
		}
	}
	return ((void *)c);
}

static void		*pf_s_cast(va_list ap, int *length, int *len)
{
	void	*a;

	a = 0;
	if (*length == 1)
	{
		a = va_arg(ap, char *);
		*len = ft_strlen(a);
	}
	else if (*length == 3)
		a = pf_wstos(va_arg(ap, wchar_t *), len);
	else
		*len = -1;
	if (*len != -1 && !a)
	{
		a = "(null)";
		*len = 6;
		*length = 1;
	}
	return (a);
}

static int		pf_puts(int *plen, int length, char *str, int slen)
{
	int	wlen;

	if (length == 3 || length == -3)
	{
		wlen = 1;
		if ((((str[0] << 24) ^ 0xF0000000) >> 28) == 0)
			wlen = 4;
		else if ((((str[0] << 24) ^ 0xE0000000) >> 28) == 0)
			wlen = 3;
		else if ((((str[0] << 24) ^ 0xC000000) >> 28) == 0)
			wlen = 2;
		if (wlen <= slen)
		{
			(length > 0) ? write(1, str, wlen) : 0;
			*plen += wlen;
			pf_puts(plen, length, str + wlen, slen - wlen);
		}
	}
	else
	{
		(length > 0) ? write(1, str, slen) : 0;
		*plen = slen;
	}
	return (*plen);
}

int				pf_s(t_pmod *p, va_list ap)
{
	void	*a;
	char	fill;
	int		i;
	int		len;
	int		plen;

	if (p->spec == 1)
		p->length = 3;
	a = pf_s_cast(ap, &p->length, &len);
	if (!(plen = 0) && len == -1)
		return (-1);
	len = (p->prec >= 0 && len > p->prec) ? p->prec : len;
	(!(p->flag % 5)) ? (len = pf_puts(&plen, p->length, a, len)) : 0;
	i = 0;
	fill = ((p->flag % 5) && !(p->flag % 3)) ? '0' : ' ';
	plen = 0;
	len = pf_puts(&plen, -(p->length), a, len);
	while (!(plen = 0) && p->width > (len + i++))
		write(1, &fill, 1);
	((p->flag % 5)) ? (len = pf_puts(&plen, p->length, a, len)) : 0;
	if (p->length == 3)
		free(a);
	return ((len > p->width) ? len : p->width);
}
