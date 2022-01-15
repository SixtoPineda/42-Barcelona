/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:36:02 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/09 13:39:44 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	signo(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2", 2);
		n = 147483648;
		return (n);
	}
	else if (n == 2147483647)
	{
		write(1, "2", 1);
		n = 147483647;
		return (n);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
		return (n);
	}
	else
	{
		return (n);
	}
}

void	printdig(int dig)
{
	int		i;
	char	num;

	i = 0;
	num = '0';
	while (i <= 9)
	{
		if (i == dig)
		{
			write(1, &num, 1);
			i = 10;
		}
		else
		{
			i++;
			num++;
		}
	}	
}

void	printnumlong(int nb, int numdig)
{		
	int				dig;
	int				cont;
	int long		numodul;

	numodul = 1;
	cont = 0;
	while (cont < (numdig - 1))
	{
		numodul = numodul * 10;
		cont++;
	}
	cont = 0;
	while (cont < numdig)
	{
		dig = (nb % (numodul * 10)) / numodul;
		printdig(dig);
		numodul = numodul / 10;
		cont++;
	}
}

void	ft_putnbr(int nb)
{	
	int	numdig;
	int	aux;

	nb = signo(nb);
	aux = nb;
	numdig = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
	}	
	else
	{
		while (aux != 0)
		{
			aux = aux / 10;
			numdig++;
		}
		printnumlong(nb, numdig);
	}
}
