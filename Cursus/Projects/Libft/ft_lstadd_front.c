/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:10:22 by syxtyn            #+#    #+#             */
/*   Updated: 2022/01/15 22:10:22 by syxtyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	+ Case: if "lst" is NULL, make to point "lst" to new
		as first list

	+ Case: "lst" and "new" have any list (no NULL)
		- Make the "next" list of "new" to be
			the first list that is pointing "lst".
		- "lst" now point to the list "new" a first list.
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL && new != NULL)
		*lst = new;
	else if (new != NULL && lst != NULL)
	{
		new->next = *lst;
		*lst = new;
	}	
}

// #include <stdio.h>

// int		main(void)
// {
// 	t_list *list;
// 	t_list *new;
// 	list = ft_lstnew("hola");
// 	int i = 25;
// 	new = ft_lstnew(&i);

// 	ft_lstadd_front(&list, new);

// 	printf("%d\n", *((int*)(list->content)));
// 	printf("%s\n", ((char*)(list->next->content)));
// 	return (0);
// }