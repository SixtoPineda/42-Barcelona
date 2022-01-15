/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:09:03 by syxtyn            #+#    #+#             */
/*   Updated: 2022/01/15 22:09:03 by syxtyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Apply the function "f" to all char in "s"
	We put it with "&" to make the function able to
		change the value of the char in "s" if it
		is necessary
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>

// void f(unsigned int i, char *c)
// {
// 	i = 0;
// 	i++;
// 	if (*c >= (int) 'a' && *c <= (int) 'z')
// 		*c = *c - 32;
// }

// int		main(void)
// {
// 	char	str2[] = "abcde";
// 	ft_striteri(str2, f);
// 	printf("%s\n", str2);
// 	return (0);
// }