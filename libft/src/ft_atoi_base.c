/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 19:36:21 by aphan             #+#    #+#             */
/*   Updated: 2016/09/25 20:52:45 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ap_basecheck(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= ('9' + base - 10));
	return ((c >= '0' && c <= '9') ||
			(c >= 'A' && c <= ('A' + base - 10)) ||
			(c >= 'a' && c <= ('a' + base - 10)));
}

int			ft_atoi_base(const char *str, int str_base)
{
	int i;
	int	sign;
	int atoi;

	i = 0;
	atoi = 0;
	if (str_base < 2 || str_base > 16)
		return (0);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ap_basecheck(str[i], str_base))
	{
		if (str[i] - 'a' >= 0)
			atoi = atoi * str_base + (str[i] - 'a' + 10);
		else if (str[i] - 'A' >= 0)
			atoi = atoi * str_base + (str[i] - 'A' + 10);
		else
			atoi = atoi * str_base + (str[i] - '0');
		i++;
	}
	return (sign * atoi);
}
