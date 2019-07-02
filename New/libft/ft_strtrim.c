/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 12:23:03 by sminnaar          #+#    #+#             */
/*   Updated: 2019/06/06 12:49:49 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*nstr;
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (ft_iswht(s[i]))
		i++;
	if (s[i] == '\0')
		return (ft_strcpy(ft_memalloc(sizeof(char) * 2), ""));
	j = ft_strlen(s) - 1;
	while (ft_iswht(s[j]))
		j--;
	if (!(nstr = (char *)ft_memalloc(sizeof(char) * (j - i + 2))))
		return (NULL);
	while (k < j - i + 1)
	{
		nstr[k] = s[i + k];
		k++;
		nstr[k] = '\0';
	}
	return (nstr);
}
