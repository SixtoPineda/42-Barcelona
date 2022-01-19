/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:55:57 by spineda-          #+#    #+#             */
/*   Updated: 2022/01/12 11:55:58 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	src_len;

	src_len = 0;
	while (str[src_len])
		src_len++;
	str = (str + (src_len - 1));
	while (*str)
	{
		if ((int)*str == ch)
			return ((char *)str);
		str--;
	}
	return (NULL);
}
