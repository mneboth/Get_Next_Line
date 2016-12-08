/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneboth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:31:05 by mneboth           #+#    #+#             */
/*   Updated: 2016/11/15 16:36:34 by mneboth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (s != (void *)0)
	{
		if ((str = ft_strnew(len)) == (void *)0)
			return ((void *)0);
		else
			return (ft_strncpy(str, s + start, len));
	}
	return ((void *)0);
}
