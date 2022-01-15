/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:44:08 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/16 12:21:49 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	aux;

	i = 0;
	while (i < size)
	{
		aux = *(tab + i);
		j = i + 1;
		while (j < size)
		{
			if (aux > *(tab + j))
			{
				*(tab + i) = *(tab + j);
				*(tab + j) = aux;
				aux = *(tab + i);
				j = i + 1;
			}
			else
			{
				j++;
			}
		}
		i++;
	}
}
