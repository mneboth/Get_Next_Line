/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneboth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 13:38:33 by mneboth           #+#    #+#             */
/*   Updated: 2016/12/14 15:20:44 by mneboth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include "libft/libft.h"

# define BUFF_SIZE 10000
# define BACKN '\n'

typedef struct	s_line
{
	int				fd;
	char			*line;
	struct s_line	*next;
}				t_line;

int				get_next_line(const int fd, char **line);

#endif
