/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:05:21 by spineda-          #+#    #+#             */
/*   Updated: 2022/01/12 13:05:23 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*arr;
	size_t	i;

	i = 0;
	arr = (char *)malloc(nmemb * size);
	if (arr == NULL)
		return (NULL);
	while (i < nmemb)
	{
		arr[i] = '\0';
		i++;
	}
	return ((void *)arr);
}
