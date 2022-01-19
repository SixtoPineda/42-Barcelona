/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:09:38 by syxtyn            #+#    #+#             */
/*   Updated: 2022/01/15 22:09:38 by syxtyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	s1_len = (size_t)ft_strlen((char *)s1);
	s2_len = (size_t)ft_strlen((char *)s2);
	str = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (s1 == NULL || s2 == NULL || str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcat(&str[s1_len], s2, s2_len + 1);
	return (str);
}

// #include <stdio.h>

// int main()
// {
// 	printf("\n%s\n\n",ft_strjoin("ABC", "DEF"));
// }