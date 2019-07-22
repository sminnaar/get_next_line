/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:01:11 by sminnaar          #+#    #+#             */
/*   Updated: 2019/06/06 13:03:29 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	wds;
	char	**n;

	i = 0;
	wds = 0;
	if (!s || (!(n = (char **)malloc(sizeof(char *) * (ft_cntwrd(s, c)) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			n[wds] = ft_strndup(s + j, i - j);
			wds++;
		}
	}
	n[wds] = NULL;
	return (n);
}
