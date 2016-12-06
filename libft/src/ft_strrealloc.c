/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 17:15:44 by aphan             #+#    #+#             */
/*   Updated: 2016/10/07 17:36:30 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrealloc(char *ptr, size_t size)
{
	char	*new;
	size_t	len;

	if (size == 0)
		size = 1;
	new = ft_memalloc(size);
	if (new == NULL)
		return (NULL);
	if (ptr)
	{
		len = ft_strlen(ptr);
		if (len > size)
			len = size;
		ft_memmove(new, ptr, len);
		free(ptr);
		ptr = NULL;
	}
	return (new);
}
