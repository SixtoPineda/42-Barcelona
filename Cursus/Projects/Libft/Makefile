# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 14:25:33 by spineda-          #+#    #+#              #
#    Updated: 2022/01/12 15:25:56 by spineda-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS =  -Wall -Werror -Wextra

all: $(NAME)

$(NAME): *.o
	$(CC) $(CFLAGS) *.c *.h -o $(NAME)

clean:
	rm -f $(NAME)
fcelan: clean
	-f $(NAME)
re: fclean all
