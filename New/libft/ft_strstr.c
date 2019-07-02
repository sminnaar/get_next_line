/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:27:32 by sminnaar          #+#    #+#             */
/*   Updated: 2019/06/06 12:59:20 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t hlen;
	size_t nlen;

	hlen = ft_strlen(haystack);
	nlen = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	while (nlen <= hlen && *haystack)
	{
		if (!(ft_strncmp(haystack, needle, nlen)))
			return ((char *)haystack);
		++haystack;
		--hlen;
	}
	return (NULL);
}
