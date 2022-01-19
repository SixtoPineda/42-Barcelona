/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:05:48 by syxtyn            #+#    #+#             */
/*   Updated: 2022/01/15 22:05:48 by syxtyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	
*/

void	ft_putnbr_fd(int n, int fd)
{
	char	*str;

	str = ft_itoa(n);
	ft_putstr_fd(str, fd);
}

// #include <stdio.h>

// int		main(void)
// {
// 	//ft_putnbr_fd(23, 1);
// 	// ft_putnbr_fd(2147483647, 2);
// 	ft_putnbr_fd(-2147483648, 1);
// 	return (0);
// }