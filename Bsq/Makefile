# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 23:05:58 by spineda-          #+#    #+#              #
#    Updated: 2021/12/21 23:06:58 by spineda-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRC = *.c
OBJECT = *.o
all : $(NAME)
$(NAME): functions.h utils1.h utils2.h
	gcc -Wall -Wextra -Werror -c $(SRC)
	gcc $(OBJECT) -o $(NAME)
clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
