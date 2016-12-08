/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneboth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 23:22:20 by mneboth           #+#    #+#             */
/*   Updated: 2016/11/15 23:33:30 by mneboth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_nbrlen_base(int n, int base)
{
	size_t len;

	if (base < 2 || base > 36)
		return (0);
	len = (n < 0 ? 2 : 1);
	while (n <= -base || n >= base)
	{
		n /= base;
		len++;
	}
	return (len);
}
