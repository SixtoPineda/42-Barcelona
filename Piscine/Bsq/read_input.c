/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:10:53 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/21 23:11:03 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "utils1.h"
#include "utils2.h"

int	read_input(char **str)
{
	int		str_size;
	int		i;
	char	aux[SIZE + 1];

	str_size = 1;
	i = 0;
	*str = malloc(sizeof(char) * SIZE + 1);
	if (!*str)
		return (print_error(2));
	while (i < SIZE)
	{
		aux[i] = '\0';
		(*str)[i] = '\0';
		i++;
	}
	i = 0;
	while (str_size > 0)
	{
		str_size = read(0, aux, SIZE);
		aux[str_size] = '\0';
		ft_strcat(*str, aux);
	}
	return (0);
}
