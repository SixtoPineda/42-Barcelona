/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 09:39:34 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/17 20:35:29 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdio.h>

int	ft_str_is_numeric(char *src);

int		main()
{
	printf("%s\n%s\n%s\n%s\n%s\n%s\n",
			ft_str_is_numeric("")?"OK":"Fail",
			!ft_str_is_numeric("ABCDEFGHIJKLMNOPQRSTUVWXZabcdefghijklmnopqrstuvwxyz")?"OK":"Fail",
			ft_str_is_numeric("0123456789")?"OK":"Fail",
			!ft_str_is_numeric(" ")?"OK":"Fail",
			!ft_str_is_numeric("\\")?"OK":"Fail",
			!ft_str_is_numeric("\n")?"OK":"Fail");
}
int	ft_str_is_numeric(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if ((*str < '0') || (*str > '9'))
			return (0);
		str++;
	}
	return (1);
}
