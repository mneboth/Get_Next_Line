/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneboth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:32:09 by mneboth           #+#    #+#             */
/*   Updated: 2016/12/03 09:47:50 by mneboth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (s1 != (void *)0 && s2 == (void *)0)
		return (ft_strdup(s1));
	else if (s1 == (void *)0 && s2 != (void *)0)
		return (ft_strdup(s2));
	else if (s1 != (void *)0 && s2 != (void *)0)
	{
		if ((str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) == (void *)0)
			return ((void *)0);
		ft_strcpy(str, s1);
		return (ft_strcat(str, s2));
	}
	return ((void *)0);
}
