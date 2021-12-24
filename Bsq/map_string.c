/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:09:16 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/21 23:09:37 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

//guardar cada caracter a partir de la segunda fila en cada casilla del mapa

void	map_string(char *buff, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*buff != '\n')
		buff++;
	buff++;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			map->map[i][j] = *buff;
			buff++;
			j++;
		}
		buff++;
		i++;
	}
}
