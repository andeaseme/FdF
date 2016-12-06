/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 17:11:51 by aphan             #+#    #+#             */
/*   Updated: 2016/09/25 23:35:13 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ap_startend(char const *s, char **start, char **end, char c)
{
	int			trufal;

	trufal = 1;
	while (*s != '\0')
	{
		if (*s != c)
			*end = (char *)s;
		if (trufal == 1 && *s != c)
		{
			*start = (char *)s;
			trufal = 0;
		}
		s++;
	}
}

char		*ft_strtrimc(char const *s, char c)
{
	char		*start;
	char		*end;
	char		*trim;

	if (!s)
		return (0);
	end = (char *)s;
	start = (char *)s;
	ap_startend(s, &start, &end, c);
	trim = ft_strsub(s, start - s, end - start + 1);
	if (end - start <= 0)
		trim[0] = '\0';
	return (trim);
}
