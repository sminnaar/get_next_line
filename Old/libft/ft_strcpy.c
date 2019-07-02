/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:50:33 by sminnaar          #+#    #+#             */
/*   Updated: 2019/06/06 11:34:50 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	if (!src[i])
	{
		*dst = '\0';
		return (dst);
	}
	while (src[i])
	{
		dst[i] = src[i];
		i++;
		dst[i] = '\0';
	}
	return (dst);
}
