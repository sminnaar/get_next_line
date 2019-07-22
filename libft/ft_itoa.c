/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 12:07:31 by sminnaar          #+#    #+#             */
/*   Updated: 2019/06/03 15:19:55 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*nstr;

	if (!(nstr = (char *)ft_memalloc(sizeof(char) * 2)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(nstr, "-2147483648"));
	if (n < 0)
	{
		nstr[0] = '-';
		nstr[1] = '\0';
		nstr = ft_strjoin(nstr, ft_itoa(-n));
	}
	else if (n >= 10)
		nstr = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else if (n >= 0 && n <= 9)
	{
		nstr[0] = n + '0';
		nstr[1] = '\0';
	}
	return (nstr);
}
