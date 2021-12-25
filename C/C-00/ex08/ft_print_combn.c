/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:05:26 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/08 20:04:45 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	eq_num_array(int sizearray, char *nums)
{
	int	iterador;
	int	interador_dos;

	iterador = 0;
	while (iterador < (sizearray - 1))
	{
		interador_dos = iterador + 1;
		while (interador_dos < (sizearray))
		{
			if (nums[iterador] == nums[interador_dos])
			{
				return (0);
			}
			interador_dos++;
		}
		iterador++;
	}
	return (1);
}

void	printnum(char *nums, int sizearray)
{
	int	aux;
	int	lastnum;
	int	count;

	count = 0;
	lastnum = 0;
	aux = eq_num_array(sizearray, nums);
	if (aux != 0)
	{
		while (lastnum < (sizearray))
		{
			if (nums[lastnum] == ((10 - sizearray + lastnum) + '0'))
			{
				count++;
			}
			lastnum++;
		}
		write(1, nums, sizearray);
		if (count != sizearray)
			write(1, ", ", 2);
	}
}

void	recursive_function(int n, int i, char *num_print, int sizearray)
{
	if (n != 0)
	{
		i = i + 1;
		while (i < (11 - n))
		{
			num_print[sizearray - n] = i + '0';
			recursive_function(n - 1, i, num_print, sizearray);
			printnum(num_print, sizearray);
			if (i == (10 - n))
			{
				num_print[sizearray - (n + 1)] = num_print[sizearray - n];
			}
			i++;
		}
	}
}

void	ft_print_combn(int n)
{
	int		i;
	char	num_print[10];
	int		sizearray;

	i = -1;
	sizearray = n;
	if ((n <= 0) || (n >= 10))
	{
		write(1, "Error: 'n' must be 0 < n < 10. \n", 32);
	}
	else
	{
		recursive_function(n, i, num_print, sizearray);
	}
}
