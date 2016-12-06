/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 21:51:59 by aphan             #+#    #+#             */
/*   Updated: 2016/09/25 22:03:54 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(char const *str)
{
	int count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
			i++;
		if (str[i] != ' ' && !(str[i] >= '\t' && str[i] <= '\r') &&
				str[i] != '\0')
			count++;
		while (str[i] != ' ' && !(str[i] >= '\t' && str[i] <= '\r') &&
				str[i] != '\0')
			i++;
	}
	return (count);
}

static int	wordlen(char const *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] != ' ' && !(str[i] >= '\t' && str[i] <= '\r') &&
			str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char		**ft_split_whitespaces(char *s)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	if (!s || (str = (char**)malloc(sizeof(char*) * wordcount(s) + 1)) == 0)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < wordcount(s))
	{
		k = 0;
		if ((str[i] = (char*)malloc(sizeof(char) * wordlen(&s[j]) + 1)) == 0)
			return (NULL);
		while (s[j] == ' ' || (s[j] >= '\t' && s[j] <= '\r'))
			j++;
		while (s[j] != ' ' && !(s[j] >= '\t' && s[j] <= '\r') && s[j] != '\0')
			str[i][k++] = s[j++];
		str[i][k] = '\0';
	}
	str[i] = NULL;
	return (str);
}
