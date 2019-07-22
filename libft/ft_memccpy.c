/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 10:14:46 by sminnaar          #+#    #+#             */
/*   Updated: 2019/05/28 11:55:46 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *)dst;
	s = (char *)src;
	while (n--)
	{
		*(d++) = *s;
		if (*(s++) == (char)c)
			return (d);
	}
	return (NULL);
}
