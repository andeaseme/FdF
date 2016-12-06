/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 20:23:32 by aphan             #+#    #+#             */
/*   Updated: 2016/11/09 17:32:49 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		init_tpfun(t_pfun *a)
{
	a[0].f = &pf_s;
	a[1].f = &pf_s;
	a[2].f = &pf_p;
	a[3].f = &pf_d;
	a[4].f = &pf_d;
	a[5].f = &pf_d;
	a[6].f = &pf_o;
	a[7].f = &pf_o;
	a[8].f = &pf_u;
	a[9].f = &pf_u;
	a[10].f = &pf_x;
	a[11].f = &pf_x;
	a[12].f = &pf_c;
	a[13].f = &pf_c;
	a[14].f = &pf_c;
	a[15].f = &pf_b;
	a[16].f = &pf_n;
	a[17].f = &pf_tint;
	return (1);
}

static int		pf_nospec(t_pmod *p, const char *a)
{
	int		i;
	char	fill;
	int		len;

	len = 1;
	(!(p->flag % 5)) ? write(1, a, len) : 0;
	i = 0;
	fill = ((p->flag % 5) && !(p->flag % 3)) ? '0' : ' ';
	while (p->width > (len + i++))
		write(1, &fill, 1);
	((p->flag % 5)) ? write(1, a, len) : 0;
	return ((len > p->width) ? len : (p->width));
}

static int		init_params(t_pmod **p)
{
	(*p)->flag = 1;
	(*p)->width = 0;
	(*p)->prec = -1;
	(*p)->length = 1;
	(*p)->dollar = 0;
	return (1);
}

int				ft_printf(const char *format, ...)
{
	va_list		args;
	t_pmod		*p;
	t_pfun		func[SPEC_COUNT];
	int			pc;

	p = (t_pmod *)malloc(sizeof(t_pmod));
	va_start(args, format);
	va_copy(p->copy, args);
	if (init_tpfun(func) && !(p->count = 0))
		while (*format)
		{
			if (*format != '%' && ++p->count)
				ft_putchar(*(format++));
			else if (init_params(&p) && (p = pf_parse(&p, &format, args)))
			{
				if (!(pc = 0) && p->spec < 0 && --format && *format)
					pc = pf_nospec(p, format++);
				else if (p->spec >= 0)
					pc = func[p->spec].f(p, args);
				p->count += pc;
			}
		}
	va_end(args);
	free(p);
	return (p->count);
}
