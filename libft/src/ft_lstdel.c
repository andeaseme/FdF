/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 15:15:48 by aphan             #+#    #+#             */
/*   Updated: 2016/09/24 17:24:44 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*forward;

	current = *alst;
	while (current != NULL)
	{
		del(current->content, current->content_size);
		forward = current->next;
		free(current);
		current = forward;
	}
	*alst = NULL;
}
