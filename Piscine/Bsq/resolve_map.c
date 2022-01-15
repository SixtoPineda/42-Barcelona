/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:11:20 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/21 23:11:23 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	resolve_map(char *buff, t_map *map)
{
	if (create_map(map))
		return (print_error(2));
	map_string(buff, map);
	find_square(map);
	return (0);
}
