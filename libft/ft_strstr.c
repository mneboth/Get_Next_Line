/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneboth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 04:43:13 by mneboth           #+#    #+#             */
/*   Updated: 2016/11/12 15:13:30 by mneboth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char *a;
	char *b;

	if (*little == '\0')
		return ((char *)big);
	while (*big != '\0')
	{
		a = (char *)big;
		b = (char *)little;
		while (*b && *a == *b)
		{
			a++;
			b++;
		}
		if (*b == '\0')
			return ((char *)big);
		big++;
	}
	return ((void *)0);
}
