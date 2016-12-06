/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 20:38:11 by aphan             #+#    #+#             */
/*   Updated: 2016/09/21 21:20:23 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i])
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (little[j] && big[i + j] && j != -1)
			{
				if (little[j] != big[i + j])
					j = -1;
				else
					j++;
				if (!little[j] && j != -1)
					return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (0);
}
