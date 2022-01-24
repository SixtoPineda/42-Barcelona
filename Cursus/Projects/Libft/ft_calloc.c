/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:05:21 by spineda-          #+#    #+#             */
/*   Updated: 2022/01/24 14:56:38 by syxtyn           ###   ########.fr       */
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
	while (i < (nmemb * size))
	{
		arr[i] = 0;
		i++;
	}
	return ((void *)arr);
}
