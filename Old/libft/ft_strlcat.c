/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 10:38:42 by sminnaar          #+#    #+#             */
/*   Updated: 2019/06/06 12:20:02 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;

	i = 0;
	j = ft_strlen(dst);
	while (src[i] && i + j < dstsize - 1 && dstsize > 0)
	{
		dst[i + j] = src[i];
		i++;
		dst[i + j] = '\0';
	}
	if (dstsize < i + j)
		return (dstsize + ft_strlen(src));
	return (j + ft_strlen(src));
}
