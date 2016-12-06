/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 21:32:34 by aphan             #+#    #+#             */
/*   Updated: 2016/09/25 21:42:20 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	size_t	len;
	char	*dst;

	len = 0;
	i = 0;
	while (s1[len] != '\0' && len < n)
		len++;
	if ((dst = (char*)malloc(sizeof(*dst) * (len + 1))) == NULL)
		return (NULL);
	while (s1[i] != '\0' && i < n)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
