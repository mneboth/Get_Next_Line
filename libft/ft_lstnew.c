/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneboth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:33:38 by mneboth           #+#    #+#             */
/*   Updated: 2016/11/15 17:01:37 by mneboth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;

	elem = (t_list *)ft_memalloc(sizeof(t_list));
	if (elem == (void *)0)
		return ((void *)0);
	if (content == (void *)0)
	{
		content_size = 0;
		elem->content = (void *)0;
	}
	else
	{
		elem->content = ft_memalloc(content_size);
		if (elem->content == (void *)0)
		{
			ft_memdel((void **)&elem);
			return ((void *)0);
		}
		ft_memcpy(elem->content, content, content_size);
	}
	elem->content_size = content_size;
	elem->next = (void *)0;
	return (elem);
}
