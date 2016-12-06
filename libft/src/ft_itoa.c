/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 22:37:23 by aphan             #+#    #+#             */
/*   Updated: 2016/09/24 21:23:55 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ap_intlen(int index)
{
	int		len;

	len = 0;
	if (index < 0)
		len++;
	if (index == 0)
		len++;
	while (index != 0)
	{
		index /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	int		index;
	char	*str;

	len = ap_intlen(n);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	if (n < 0)
		str[0] = '-';
	str[len] = '\0';
	while (len-- > 0)
	{
		index = n % 10;
		if (index < 0)
			index = -index;
		str[len] = index + '0';
		n /= 10;
		if (n == 0)
			break ;
	}
	return (str);
}
