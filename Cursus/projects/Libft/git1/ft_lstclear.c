/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:21:39 by syxtyn            #+#    #+#             */
/*   Updated: 2022/01/15 22:21:39 by syxtyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	- Iterate over the list of elements
	- Apply the free function
	- Use aux to be able to go to the next element in "lst"
	- Put null the list.
*/

#include <stdio.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*aux;

	current = *lst;
	while (current->next != NULL)
	{
		aux = current;
		ft_lstdelone(current, del);
		current = aux->next;
	}
	*lst = NULL;
}
