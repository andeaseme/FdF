/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 14:31:16 by aphan             #+#    #+#             */
/*   Updated: 2016/09/24 21:39:03 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t index;

	if (s1 && s2)
	{
		if (n == 0)
			return (1);
		index = 1;
		while (*s1 == *s2)
		{
			if (*s1 == '\0' || index == n)
				return (1);
			s1++;
			s2++;
			index++;
		}
	}
	return (0);
}
