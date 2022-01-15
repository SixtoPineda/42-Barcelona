/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:14:05 by spineda-          #+#    #+#             */
/*   Updated: 2022/01/10 13:14:07 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	cont;

	cont = 0;
	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i])
	{
		j = 0;
		while ((str[i + j] == to_find[j]) && (str[i + j] != '\0') && cont < n)
		{
			if (to_find[j + 1] == '\0')
			{
				return ((char *)&str[i]);
			}
			cont++;
			j++;
		}
		cont++;
		i++;
	}
	return (NULL);
}
