/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:14:29 by sminnaar          #+#    #+#             */
/*   Updated: 2019/05/28 13:33:05 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *src;
	unsigned char chr;

	src = (unsigned char *)s;
	chr = (unsigned char)c;
	while (n--)
	{
		if (*src == chr)
			return (src);
		++src;
	}
	return (NULL);
}
