/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 10:24:37 by sminnaar          #+#    #+#             */
/*   Updated: 2019/05/31 15:06:27 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*nstr;

	if (!(nstr = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(nstr, size + 1);
	return (nstr);
}
