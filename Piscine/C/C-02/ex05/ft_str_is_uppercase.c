/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 09:47:36 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/17 20:36:38 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdio.h>

int	ft_str_is_uppercase(char *src);

int		main()
{
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
			ft_str_is_uppercase("")?"OK":"Fail",
			ft_str_is_uppercase("ABCDEFGHIJKLMNOPQRSTUVWXZ")?"OK":"Fail",
			!ft_str_is_uppercase("ABCDEFGHIJKLMNOPQRSTUVWXZabcdefghijklmnopqrstuvwxyz")?"OK":"Fail",
			!ft_str_is_uppercase("0123456789")?"OK":"Fail",
			!ft_str_is_uppercase(" ")?"OK":"Fail",
			!ft_str_is_uppercase("\\")?"OK":"Fail",
			!ft_str_is_uppercase("\n")?"OK":"Fail");
}
int	ft_str_is_uppercase(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if ((*str < 'A') || (*str > 'Z'))
			return (0);
		str++;
	}
	return (1);
}
