/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:12:46 by syxtyn            #+#    #+#             */
/*   Updated: 2022/01/15 22:12:46 by syxtyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	- Create a "str" with the same size of "s"
	- Iterate "s" and copy the result
		of applying de function "f" to "s"
		inside the new string "str"
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	str = (char *) malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, (char)s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// #include <stdio.h>

// char f(unsigned int i, char c)
// {
// 	i = 0;
// 	i++;
// 	char str;
// 	str = c + 1;
// 	return (str);
// }

// int main()
// {
// 	char str1[] = "abc";
// 	char* str2;
// 	str2 = fft_strmapi(str1, *f);
// 	printf("%s\n", str2);
// }