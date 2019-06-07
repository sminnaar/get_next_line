/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 12:08:07 by sminnaar          #+#    #+#             */
/*   Updated: 2019/05/27 16:43:42 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	cha = (char)c;
	char		*r_out;

	r_out = NULL;
	while (*s)
	{
		if (*s == cha)
			r_out = (char*)s;
		++s;
	}
	if (*s == cha)
		return ((char*)s);
	return (r_out);
}
