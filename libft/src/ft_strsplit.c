/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 17:51:56 by aphan             #+#    #+#             */
/*   Updated: 2016/09/24 22:07:22 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ap_wc(char const *s, char c)
{
	int		i;
	int		wordfound;
	int		count;

	i = 0;
	wordfound = 1;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && wordfound == 0)
			wordfound = 1;
		if (s[i] != c && wordfound == 1)
		{
			wordfound = 0;
			count++;
		}
		i++;
	}
	return (count);
}

static int	ap_charcount(int position, const char *s, char c)
{
	int i;

	i = position;
	while (s[i] != c)
		i++;
	return (i - position);
}

static int	ap_wordposition(int i, const char *s, char c)
{
	while (s[i] != '\0')
	{
		if (s[i] != c)
			break ;
		i++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		wnum;
	int		index[2];
	int		wlen;
	char	**split;

	if (!s)
		return (0);
	wnum = 0;
	index[1] = 0;
	if ((split = (char **)malloc(sizeof(char *) * (ap_wc(s, c) + 1))) == NULL)
		return (0);
	while (wnum < ap_wc(s, c))
	{
		index[0] = 0;
		index[1] = ap_wordposition(index[1], s, c);
		wlen = ap_charcount(index[1], s, c);
		if ((split[wnum] = (char *)malloc(sizeof(char) * (wlen + 1))) == NULL)
			return (0);
		while (index[0] < wlen)
			split[wnum][index[0]++] = s[index[1]++];
		split[wnum][index[0]] = '\0';
		wnum++;
	}
	split[ap_wc(s, c)] = NULL;
	return (split);
}
