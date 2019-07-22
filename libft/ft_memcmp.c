/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:44:43 by sminnaar          #+#    #+#             */
/*   Updated: 2019/05/28 16:28:23 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *st1;
	unsigned char *st2;

	st1 = (unsigned char*)s1;
	st2 = (unsigned char*)s2;
	while (n--)
	{
		if (*st1 != *st2)
			return (*st1 - *st2);
		++st1;
		++st2;
	}
	return (0);
}
