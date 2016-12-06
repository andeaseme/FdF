/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:34:44 by aphan             #+#    #+#             */
/*   Updated: 2016/09/25 16:27:01 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d1;
	unsigned const char *s1;

	d1 = (unsigned char *)dst;
	s1 = (unsigned const char *)src;
	if (s1 < d1)
		while ((int)(len--) > 0)
			*(d1 + len) = *(s1 + len);
	else if (s1 > d1)
		while ((int)(len--) > 0)
			*d1++ = *s1++;
	return (dst);
}
