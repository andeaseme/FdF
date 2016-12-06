/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:43:09 by aphan             #+#    #+#             */
/*   Updated: 2016/11/22 22:52:53 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *lst, size_t size)
{
	t_list	*new;

	if (lst == NULL)
		return (NULL);
	new = ft_lstnew(lst->content, size * (lst->content_size));
	new->content_size = lst->content_size;
	new->next = ft_lstdup(lst->next, size);
	return (new);
}
