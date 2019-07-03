/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 14:47:32 by sminnaar          #+#    #+#             */
/*   Updated: 2019/06/25 10:29:14 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_repnew(char *s, int c, int d)
{
	char	*new;
	size_t	i;

	i = 0;
	new = ft_strdup(s);
	while (new[i] != '\0')
	{
		if (new[i] == c)
			new[i] = d;
		i++;
	}
	return (new);
}
