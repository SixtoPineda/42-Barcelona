/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_free_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:09:54 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/21 23:10:11 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "utils2.h"

void	print_and_free_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if ((i >= map->start_x && i < (map->start_x + map->max))
				&& (j >= map->start_y && j < (map->start_y + map->max)))
				ft_putchar(map->full);
			else
				ft_putchar(map->map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	free_map(map);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}
