/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:19:42 by syxtyn            #+#    #+#             */
/*   Updated: 2022/01/15 22:19:42 by syxtyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Itera la lista ’lst’ y aplica la función ’f’ al
	contenido de cada elemento.
*/

#include <stdio.h>

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	current = lst;
	if (lst == NULL || f == NULL)
		return ;
	while (current != NULL)
	{
		f(current->content);
		if (current->next == NULL)
			return ;
		current = current->next;
	}
}
