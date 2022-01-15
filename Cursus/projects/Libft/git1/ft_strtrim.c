/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:19:26 by syxtyn            #+#    #+#             */
/*   Updated: 2022/01/15 22:19:26 by syxtyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Use "set" as Dicc of symb inside s1 to cut 
	at the beginning and the end of s1
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	start = 0;
	end = (ft_strlen((char *)s1) - 1);
	while (s1[start] && ft_strchr((char *)set, (int)s1[start]))
		start++;
	while (end >= 0 && ft_strchr((char *)set, (int)s1[end]))
		end--;
	str = (char *) malloc((end - start + 2) * sizeof(char));
	if (s1 == NULL || str == NULL)
		return (NULL);
	ft_strlcpy(str, &s1[start], (end - start + 2));
	return (str);
}

// #include <stdio.h>

// int main()
// {
// 	char *s = ft_strtrim("1holaq", "1hq");
// 	if (s[3] == '\0')
// 		printf("\n%s\n\n", s);

// }