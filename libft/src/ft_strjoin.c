/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 16:55:13 by aphan             #+#    #+#             */
/*   Updated: 2016/09/24 21:42:38 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		index;
	char	*join;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * (len + 1));
	if (join == 0)
		return (NULL);
	index = 0;
	while (*s1 != '\0')
	{
		join[index] = *s1;
		index++;
		s1++;
	}
	while (*s2 != '\0')
	{
		join[index] = *s2;
		index++;
		s2++;
	}
	join[index] = '\0';
	return (join);
}
