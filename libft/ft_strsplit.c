/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneboth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:41:39 by mneboth           #+#    #+#             */
/*   Updated: 2016/11/15 15:53:14 by mneboth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (s[j] != '\0')
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		if (s[j] != '\0')
			i++;
		while (s[j] != '\0' && s[j] != c)
			j++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	size_t		i;
	size_t		j;
	size_t		n;

	i = 0;
	j = 0;
	n = 0;
	if (s == (void *)0)
		return ((void *)0);
	tab = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (tab == (void *)0)
		return ((void *)0);
	while (s[i] != '\0' && s[n] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		n = i;
		while (s[n] != '\0' && s[n] != c)
			n++;
		tab[j++] = ft_strsub(s, i, n - i);
		i = n;
	}
	tab[ft_count_words(s, c)] = 0;
	return (tab);
}
