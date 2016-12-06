/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:20:05 by aphan             #+#    #+#             */
/*   Updated: 2016/11/09 15:38:50 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		pf_flagparse(const char **current, int flag)
{
	while (pf_isflag(**current))
	{
		if (**current == '#')
			flag *= 2;
		else if (**current == '0')
			flag *= 3;
		else if (**current == '-')
			flag *= 5;
		else if (**current == '+')
			flag *= 7;
		else if (**current == ' ')
			flag *= 11;
		(*current)++;
	}
	return (flag);
}

static int		pf_widthparse(const char **current, va_list ap, t_pmod **p)
{
	if (**current == '*')
	{
		(*p)->dollar = 1;
		(*current)++;
		(*p)->width = va_arg(ap, int);
	}
	else if (ft_isdigit(**current))
	{
		(*p)->width = ft_atoi((*current)++);
		while (ft_isdigit(**current))
			(*current)++;
		if (!((*p)->dollar) && **current == '$')
		{
			va_copy(ap, (*p)->copy);
			while (--(*p)->width)
				va_arg(ap, void *);
			(*current)++;
		}
	}
	if (**current == '*' || ft_isdigit(**current))
		(*p)->width = pf_widthparse(current, ap, p);
	return ((*p)->width);
}

static int		pf_precparse(const char **current, va_list ap, t_pmod **p)
{
	if (**current == '.')
	{
		(*p)->dollar = 1;
		(*current)++;
		if (**current == '*')
		{
			(*p)->prec = va_arg(ap, int);
			(*current)++;
		}
		else
		{
			(*p)->prec = ft_atoi(*current);
			while (ft_isdigit(**current))
				(*current)++;
		}
	}
	return ((*p)->prec);
}

static int		pf_lengthparse(const char **current, int length)
{
	if (pf_islength(**current))
	{
		if (**current == 'h')
			length *= 2;
		else if (**current == 'l')
			length *= 3;
		else if (**current == 'j')
			length *= 5;
		else if (**current == 'z')
			length *= 7;
		(*current)++;
		if (**current == 'h' && *(*current - 1) == 'h' && (*current)++)
			length = 11 * (length / 2);
		if (**current == 'l' && *(*current - 1) == 'l' && (*current)++)
			length = 13 * (length / 3);
	}
	if (pf_islength(**current))
		length = pf_lengthparse(current, length);
	return (length);
}

t_pmod			*pf_parse(t_pmod **params, const char **current, va_list ap)
{
	const char *holder;

	(*current)++;
	holder = *current;
	(*params)->flag = pf_flagparse(current, (*params)->flag);
	(*params)->width = pf_widthparse(current, ap, params);
	if ((*params)->width < 0)
	{
		(*params)->flag *= 5;
		(*params)->width *= -1;
	}
	(*params)->prec = pf_precparse(current, ap, params);
	(*params)->length = pf_lengthparse(current, (*params)->length);
	(*params)->spec = pf_isspec(**current);
	(*params)->base = 10;
	(*current)++;
	if ((*params)->spec < 0 && !(*current == (holder + 1)))
	{
		(*current) -= 2;
		pf_parse(params, current, ap);
	}
	return (*params);
}
