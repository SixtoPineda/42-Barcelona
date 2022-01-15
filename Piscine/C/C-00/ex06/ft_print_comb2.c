/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:25:47 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/09 09:17:08 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	printlet(int i, char let, int numlet)
{
	while (i <= 9)
	{
		if (i == numlet)
		{
			write(1, &let, 1);
		}
		let++;
		i++;
	}
}

void	num2let(int x, int y, int z, int w)
{
	int		i;
	char	let;

	i = 0;
	let = '0';
	printlet(i, let, x);
	printlet(i, let, y);
	write(1, " ", 1);
	printlet(i, let, z);
	printlet(i, let, w);
	if (x == 9 && y == 8 && z == 9 && w == 9)
	{
	}
	else
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	extractnums(int a, int b)
{
	int	x;
	int	y;
	int	z;
	int	w;

	x = a / 10;
	y = a % 10;
	z = b / 10;
	w = b % 10;
	num2let(x, y, z, w);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{	
			extractnums(a, b);
			b++;
		}
		a++;
	}
}
