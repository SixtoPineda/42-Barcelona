/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:12:12 by syxtyn            #+#    #+#             */
/*   Updated: 2022/01/15 22:12:12 by syxtyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	- Obtain the first element of the list and point
		to it with current.
	- Iterate over the list thanks to current.
	- When we find the "next" as NULL, is the last element
		so, we make it to point to the "new" element.
*/

#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	current = *lst;
	if (new != NULL)
	{
		if (lst == NULL)
			*lst = new;
		else
		{
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = new;
		}
	}
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
// 	last = ft_lstnew("jeje");
// 	ft_lstadd_front(&list, new); //add the new lits to list "list" 

// 	printf("%d\n", *((int*)(list->content)));
// 	printf("%s\n", ((char*)(list->next->content)));

// 	//put last in the last position of the list
// 	ft_lstadd_back(&list, last);
// 	printf("String final: %s\n", ((char*)(list->next->next->content)));
// 	t_list *final_list = ft_lstlast(list);
//  	printf("String final: %s\n", ((char*)(final_list->content)));

// 	return (0);
// }