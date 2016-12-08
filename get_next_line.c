/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneboth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 23:36:37 by mneboth           #+#    #+#             */
/*   Updated: 2016/12/08 06:56:34 by mneboth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_mem_concat(char *str, char *buf)
{
	char *tmp;

	tmp = ft_strjoin(str, buf);
	ft_strdel(&str);
	return (tmp);
}

static int		ft_get_line(char **line, char *buf, char *overf)
{
	char *tmp;

	if ((tmp = ft_strchr(buf, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(buf);
		ft_memmove(overf, tmp + 1, ft_strlen(tmp + 1) + 1);
		return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char overf[256][BUFF_SIZE + 1];
	char		buf[BUFF_SIZE + 1];
	char		*str;
	int			ret;

	if (fd < 0 || fd > 256 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	if (ft_get_line(line, overf[fd], overf[fd]) == 1)
		return (1);
	str = ft_strdup(overf[fd]);
	ft_memset(overf[fd], 0, BUFF_SIZE + 1);
	ft_bzero(buf, BUFF_SIZE + 1);
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		str = ft_mem_concat(str, buf);
		if (ft_get_line(line, str, overf[fd]) == 1)
		{
			ft_strdel(&str);
			return (1);
		}
	}
	return ((*line = str) && ft_strlen(*line) != 0);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		ret_value;
	char	*line;

	line = NULL;
	fd = open(argv[1], O_RDONLY);
	if (argc > 1)
	if (fd == -1)
		return (-1);
	ret_value = 1;
	while (ret_value == 1)
	{
		ret_value = get_next_line(fd, &line);
		printf("%d || %s\n", ret_value, line);
		ft_strdel(&line);
	}
	close(fd);
	return (0);
}
