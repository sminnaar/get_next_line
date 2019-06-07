/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 13:25:18 by sminnaar          #+#    #+#             */
/*   Updated: 2019/05/29 13:33:11 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t hlen;
	size_t nlen;

	hlen = ft_strlen(haystack);
	nlen = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	while (nlen <= hlen && *haystack && len >= nlen)
	{
		if (!(ft_strncmp(haystack, needle, nlen)))
			return ((char *)haystack);
		++haystack;
		--hlen;
		--len;
	}
	return (NULL);
}
