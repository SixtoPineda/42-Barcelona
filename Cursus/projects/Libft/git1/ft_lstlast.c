/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:13:24 by syxtyn            #+#    #+#             */
/*   Updated: 2022/01/15 22:13:24 by syxtyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Iterate over lst and when we find
	that the "next" element in list is
	NULL, we return that element as last element
	inside the list.
*/

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	current = lst;
	while (current != NULL)
	{
		if (current->next == NULL)
			return (current);
		current = current->next;
	}
	return (current);
}

// #include <stdio.h>

// int		main(void)
// {
// 	t_list *list;
// 	t_list *new;
// 	t_list *last;
// 	int i = 25;

// 	//Create the two lists
// 	list = ft_lstnew("hola");
// 	new = ft_lstnew(&i);

// 	ft_lstadd_front(&list, new); //add the new lits to list "list" 

// 	printf("%d\n", *((int*)(list->content)));
// 	printf("%s\n", ((char*)(list->next->content)));

// 	//obtain last element of the list
// 	last = ft_lstlast(list);
// 	printf("%s\n", ((char*)(last->content)));

// 	return (0);
// }