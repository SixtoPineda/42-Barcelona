/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:52:01 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/09 12:41:15 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	printschar(char u, char d, char c)
{
	if (u != d && u != c && c != d)
	{
		ft_putchar(u);
		ft_putchar(d);
		ft_putchar(c);
		if ((u == '7') && (d == '8') && (c == '9'))
		{
		}
		else
		{
			write(1, ", ", 2);
		}
	}
}

void	ft_print_comb(void)
{
	char	u;
	char	d;
	char	c;

	u = '0';
	while (u <= '7')
	{
		d = u + 1;
		while (d <= '8')
		{
			c = d + 1;
			while (c <= '9')
			{
				printschar(u, d, c);
				c++;
			}
			d++;
		}
		u++;
	}
}
