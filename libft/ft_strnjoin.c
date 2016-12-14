/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneboth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 13:41:26 by mneboth           #+#    #+#             */
/*   Updated: 2016/12/14 13:42:44 by mneboth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char *)ft_memalloc(ft_strlen(s1) + n + 1)))
		return (NULL);
	ft_memcpy(str, s1, n);
	if (n > ft_strlen(str))
	{
		n -= ft_strlen(str);
		ft_strncat(str, s2, n);
	}
	return (str);
}
