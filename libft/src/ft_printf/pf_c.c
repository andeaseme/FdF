/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 20:22:38 by aphan             #+#    #+#             */
/*   Updated: 2016/11/12 16:21:26 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	*pf_c_cast(va_list ap, int length, int *len, int spec)
{
	char	*a;

	a = ft_strnew(sizeof(wchar_t));
	if (spec == 14 && (*len = 1))
		a[0] = 37;
	else if (length == 1 && (*len = 1))
		a[0] = va_arg(ap, int);
	else if (length == 3)
		*len = pf_wctoc(va_arg(ap, wchar_t), a);
	return (a);
}

int			pf_c(t_pmod *p, va_list ap)
{
	char	*a;
	char	fill;
	int		i;
	int		len;

	if (p->spec == 13)
		p->length = 3;
	if (!(a = pf_c_cast(ap, p->length, &len, p->spec)))
		return (-1);
	(!(p->flag % 5)) ? write(1, a, len) : 0;
	i = 0;
	fill = ((p->flag % 5) && !(p->flag % 3)) ? '0' : ' ';
	while (p->width > (len + i++))
		write(1, &fill, 1);
	(p->flag % 5) ? write(1, a, len) : 0;
	free(a);
	return ((len > p->width) ? len : p->width);
}
