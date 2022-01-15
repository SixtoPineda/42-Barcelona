/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:20:22 by syxtyn            #+#    #+#             */
/*   Updated: 2022/01/15 22:20:22 by syxtyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	
*/

void	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (s == NULL)
		return ;
	while (i < s_len)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

// #include <stdio.h>

// int		main(void)
// {
// 	ft_putstr_fd("hola", 2);
// 	return (0);
// }