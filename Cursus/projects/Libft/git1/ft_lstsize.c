/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:20:45 by syxtyn            #+#    #+#             */
/*   Updated: 2022/01/15 22:20:45 by syxtyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Create a aux struct "t_list" to iterate 
	over the list "lst".
*/

int	ft_lstsize(t_list *lst)
{
	int		cont;
	t_list	*current;

	current = lst;
	cont = 0;
	while (current != NULL && lst != NULL)
	{
		cont++;
		current = current->next;
	}
	return (cont);
}

// #include <stdio.h>

// int		main(void)
// {
// 	t_list *list;
// 	t_list *new;
// 	int i = 25;

// 	//Create the two lists
// 	list = ft_lstnew("hola");
// 	new = ft_lstnew(&i);

// 	ft_lstadd_front(&list, new); //add the new lits to list "list" 

// 	printf("%d\n", *((int*)(list->content)));
// 	printf("%s\n", ((char*)(list->next->content)));

// 	//obtain the number of lists (2)
// 	printf("Size list: %d\n", ft_lstsize(list));
// 	//obtain the number of lists if is NULL (0)
// 	list = NULL;
// 	printf("Size list: %d", ft_lstsize(list));
// 	return (0);
// }