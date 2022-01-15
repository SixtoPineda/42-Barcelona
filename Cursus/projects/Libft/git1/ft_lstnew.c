/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:06:47 by syxtyn            #+#    #+#             */
/*   Updated: 2022/01/15 22:06:47 by syxtyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	- Create a list of structs of type "t_list"
	- Reserve memory to the list of structs
		Verify the malloc
	- Introduce de content
	- Initialize the first struct fo our list
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *) malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

// #include <stdio.h>

// int		main(void)
// {
// 	t_list *list;
// 	list = ft_lstnew("hola");
// 	printf("%s\n", (char *)list->content);

// 	int i = 25;
// 	list->next = ft_lstnew(&i);
// 	printf("%d\n", *((int*)(list->next->content)));
// 	return (0);
// }