/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 20:14:45 by aphan             #+#    #+#             */
/*   Updated: 2016/11/09 17:30:42 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "libft.h"

# define SPEC "sSpdDioOuUxXcC%bnT"
# define SPEC_COUNT 18

typedef struct	s_pmod
{
	int			flag;
	int			width;
	int			prec;
	int			length;
	int			spec;
	int			base;
	intmax_t	count;
	va_list		copy;
	int			dollar;
}				t_pmod;

typedef struct	s_pfun
{
	int		(*f)(t_pmod *, va_list);
}				t_pfun;

int				pf_isspec(int a);
int				pf_isflag(int a);
int				pf_islength(int a);
int				pf_putspace(int plen, t_pmod *p);
t_pmod			*pf_parse(t_pmod **params, const char **current, va_list ap);
int				pf_wctoc(wchar_t wc, char *c);
int				pf_s(t_pmod *p, va_list ap);
int				pf_nbrlen(intmax_t value, const int base);
int				pf_d(t_pmod *p, va_list ap);
int				pf_unbrlen(uintmax_t value, const int base);
void			pf_putunbr(uintmax_t nb, t_pmod *p, int len);
uintmax_t		pf_u_cast(va_list ap, int length, int base, int *len);
int				pf_u(t_pmod *p, va_list ap);
int				pf_p(t_pmod *p, va_list ap);
int				pf_o(t_pmod *p, va_list ap);
int				pf_x(t_pmod *p, va_list ap);
int				pf_c(t_pmod *p, va_list ap);
int				pf_b(t_pmod *p, va_list ap);
int				pf_n(t_pmod *p, va_list ap);
int				pf_tint(t_pmod *p, va_list ap);
int				ft_printf(const char *format, ...);

#endif
