/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 12:42:42 by aphan             #+#    #+#             */
/*   Updated: 2016/11/16 16:46:45 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*gnl_strcutend(char *text, char *ptr)
{
	char	*new;

	if (!(ptr) || !(*ptr))
		new = ft_strnew(1);
	else
		new = ft_strdup(ptr);
	free(text);
	text = NULL;
	return (new);
}

static char		*gnl_strjoinalloc(char *s1, char *s2)
{
	char	*new;

	if (s1)
	{
		new = ft_strjoin(s1, s2);
		free(s1);
	}
	else
		new = ft_strdup(s2);
	ft_bzero(s2, BUFF_SIZE);
	return (new);
}

static t_list	*gnl_getlist(const int fd, t_list **list)
{
	t_list	*node;

	node = *list;
	while (node && (int)node->content_size != fd)
		node = node->next;
	if (!node)
	{
		ft_lstadd(list, ft_lstnew(0, 1));
		(*list)->content_size = fd;
		node = *list;
	}
	return (node);
}

static int		gnl_getline(const int fd, char **line, void **text)
{
	char	*n_chr;
	char	*buf;
	int		ret;
	int		nidx;

	buf = ft_strnew(BUFF_SIZE + 1);
	*line = NULL;
	ret = (buf) ? 1 : -1;
	while (!(*line) && (ret > 0 || (*text && ((char *)(*text))[0])))
	{
		if (*text && ((n_chr = ft_strchr(*text, '\n')) || ret == 0))
		{
			nidx = n_chr ? n_chr - (char *)(*text) : ft_strlen(*text);
			*line = ft_strsub(*text, 0, nidx);
			*text = gnl_strcutend(*text, n_chr ? n_chr + 1 : 0);
			ret = 1;
		}
		else if ((ret = read(fd, buf, BUFF_SIZE)))
			*text = gnl_strjoinalloc(*text, buf);
	}
	*line = *line ? *line : ft_strnew(1);
	free(buf);
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	static t_list	*list;
	t_list			*node;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	node = gnl_getlist(fd, &list);
	ret = gnl_getline(fd, line, &(node->content));
	if (ret == -1)
		return (-1);
	if (ret > 0)
		return (1);
	return (0);
}
