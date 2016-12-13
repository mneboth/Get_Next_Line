/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneboth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:42:47 by mneboth           #+#    #+#             */
/*   Updated: 2016/12/13 16:02:47 by mneboth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_strrlen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

char			*ft_concatenate(char *s1, char *s2)
{
	char		*s3;
	size_t		size;

	s3 = NULL;
	if (s1 && s2)
	{
		size = (size_t)ft_strrlen(s2, '\n');
		s3 = ft_strnew(ft_strlen(s1) + size);
		if (!s3)
			return (NULL);
		s3 = ft_strcpy(s3, s1);
		s3 = ft_strncat(s3, s2, size);
	}
	return (s3);
}

static t_gnl	*find_fd(t_gnl **begin_list, int fd)
{
	if (*begin_list == NULL)
	{
		*begin_list = (t_gnl*)ft_memalloc(sizeof(t_gnl));
		(*begin_list)->fd = fd;
		return (*begin_list);
	}
	else if ((*begin_list)->next == NULL)
	{
		if ((*begin_list)->fd == fd)
			return (*begin_list);
		(*begin_list)->next = (t_gnl*)ft_memalloc(sizeof(t_gnl));
		(*begin_list)->next->fd = fd;
		return ((*begin_list)->next);
	}
	else
	{
		if ((*begin_list)->fd == fd)
			return (*begin_list);
		return (find_fd(&(*begin_list)->next, fd));
	}
	return (*begin_list);
}

int				get_next_line(int fd, char **line)
{
	static t_gnl	*begin = NULL;
	t_gnl			*gnl;
	int				size;

	gnl = find_fd(&begin, fd);
	*line = ft_strnew(0);
	if (!POS || (POS == RET))
	{
		POS = 0;
		if ((RET = read(fd, BUFF, BUFF_SIZE)) <= 0)
			return (RET);
		BUFF[RET] = '\0';
	}
	while ((size = ft_strrlen(&BUFF[POS], '\n')) == RET - POS && RET)
	{
		*line = ft_strjoin(*line, &BUFF[POS]);
		POS = 0;
		RET = read(fd, BUFF, BUFF_SIZE);
		BUFF[RET] = '\0';
	}
	*line = ft_concatenate(*line, &BUFF[POS]);
	POS = (RET == BUFF_SIZE || size < RET) ? POS + size + 1 : 0;
	return (1);
}
