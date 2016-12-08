/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneboth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:33:57 by mneboth           #+#    #+#             */
/*   Updated: 2016/11/15 23:07:04 by mneboth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isspace(int c)
{
	if (c == ' ' || c == '\n')
		return (1);
	if (c == '\t' || c == '\r')
		return (1);
	if (c == '\v' || c == '\f')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	if (s)
	{
		j = ft_strlen(s) - 1;
		while (s[i] && ft_isspace(s[i]))
			i++;
		while (j > 0 && ft_isspace(s[j]))
			j--;
		j++;
		if (i < j)
		{
			if ((str = ft_strsub(s, i, j - i)))
				return (str);
		}
		else
			return (ft_strnew(0));
	}
	return ((void *)0);
}
