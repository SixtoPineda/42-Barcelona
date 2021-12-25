/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:39:49 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/13 16:49:40 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	aux;
	int	bucle_time;

	bucle_time = (size / 2);
	i = 0;
	while (i < bucle_time)
	{
		aux = *(tab + i);
		*(tab + i) = *(tab + (size - (1 + i)));
		*(tab + (size - (1 + i))) = aux;
	i++;
	}
}
