/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneboth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 13:46:25 by mneboth           #+#    #+#             */
/*   Updated: 2016/12/14 13:48:49 by mneboth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*str;

	if (!(str = (char *)ft_memalloc(n + 1)))
		return (NULL);
	ft_memcpy(str, s1, n);
	return (str);
}
