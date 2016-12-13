/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneboth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:42:56 by mneboth           #+#    #+#             */
/*   Updated: 2016/12/13 16:02:52 by mneboth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

# define BUFF_SIZE 10
# define RET gnl->ret
# define BUFF  gnl->buff
# define SIZE gnl->size
# define POS gnl->pos
# define FD gnl->fd

typedef struct	s_gnl
{
	int				ret;
	char			buff[BUFF_SIZE + 1];
	int				pos;
	int				fd;
	struct s_gnl	*next;
}				t_gnl;

int				get_next_line(int const fd, char **line);
void			ft_print_list(t_gnl *begin, int j);

#endif
