# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mneboth <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/25 20:10:02 by mneboth           #+#    #+#              #
#    Updated: 2016/12/07 03:53:50 by mneboth          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

SRC =	get_next_line.c

OBJ = $(SRC:.c=.o)
INC = -I libft -I includes
LIB = -L libft/ -lft
FLAGS = -Wall -Wextra -Werror

$(NAME):	$(OBJ)
	@make -C libft/ re
	@gcc -o $(NAME) $(OBJ) $(LIB)
	@echo "\033[32;1m> $(NAME) is on.\n> You can now run it!\033[0m"

$(OBJ): %.o: %.c
	@gcc $(FLAGS) $(INC) -c $< -o $@

all:		$(NAME)

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean
	@echo "\033[31m> Objects files are deleted.\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "\033[31m> $(NAME) is off.\033[0m"

re: fclean all

.PHONY: all clean fclean re
