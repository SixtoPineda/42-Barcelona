/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 11:58:09 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/12 16:44:22 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	check_number_cuatro(char *argv[])
{
	int	i;

	i = 0;
	if (((argv[1][2] == '4') && (argv[1][22] != '2'))
		|| ((argv[1][4] == '4') && (argv[1][15] != '2'))
			|| ((argv[1][10] == '4') && (argv[1][16] != '2'))
			|| ((argv[1][12] == '4') && (argv[1][24] != '2'))
			|| ((argv[1][18] == '4') && (argv[1][6] != '2'))
			|| ((argv[1][19] == '4') && (argv[1][14] != '2'))
			|| ((argv[1][26] == '4') && (argv[1][0] != '2'))
			|| ((argv[1][28] == '4') && (argv[1][8] != '2')))
		return (0);
	return (1);
}

int	check_number_tres(char *argv[])
{
	int	i;

	i = 0;
	if (((argv[1][0] == '1') && (argv[1][16] != '1'))
		|| ((argv[1][16] == '1') && (argv[1][0] != '1'))
			|| ((argv[1][6] == '1') && (argv[1][24] != '1'))
			|| ((argv[1][24] == '1') && (argv[1][6] != '1'))
			|| ((argv[1][22] == '1') && (argv[1][8] != '1'))
			|| ((argv[1][8] == '1') && (argv[1][22] != '1'))
			|| ((argv[1][30] == '1') && (argv[1][14] != '1'))
			|| ((argv[1][14] == '1') && (argv[1][30] != '1'))
			|| ((argv[1][0] == '4') && (argv[1][20] != '2'))
			|| ((argv[1][16] == '4') && (argv[1][4] != '2'))
			|| ((argv[1][22] == '4') && (argv[1][12] != '2'))
			|| ((argv[1][8] == '4') && (argv[1][18] != '2'))
			|| ((argv[1][14] == '4') && (argv[1][26] != '2'))
			|| ((argv[1][30] == '4') && (argv[1][10] != '2'))
			|| ((argv[1][24] == '4') && (argv[1][2] != '2'))
			|| ((argv[1][6] == '4') && (argv[1][28] != '2')))
		return (0);
	return (1);
}

//Check con los valores opouestos a cada rowX y colX

int	check_number_dos(char *argv[])
{
	int	i;
	int	cont;

	cont = 0;
	i = 0;
	while (argv[1][i] != '\0' && (cont < 9))
	{
		if (cont != 4)
		{
			if ((argv[1][i] == '4') && (argv[1][i + 8] != '1')
					|| ((argv[1][i] == '1') && (argv[1][i + 8] == '1'))
					|| ((argv[1][i] == '2') && (argv[1][i + 8] == '4'))
					|| ((argv[1][i] == '3') && (argv[1][i + 8] >= '3')))
				return (0);
			cont++;
			i = i + 2;
		}
		else
		{
			cont++;
			i = i + 8;
		}
	}
	return (1);
}

//Check de que se cumple el numero de numeros por tipo de numero
int	correct_numbers(char *argv[])
{
	int	i;
	int	four;
	int	one;

	i = 0;
	four = 0;
	one = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == '4')
			four++;
		else if (argv[1][i] == '1')
			one++;
		i++;
	}
	if ((four > 4) || (one > 4))
		return (0);
	else if ((one < four) || (four == 4) && (one != 4))
		return (0);
	else if (check_number_dos(argv) == 0)
		return (0);
	else if (check_number_tres(argv) == 0)
		return (0);
	return (1);
}

int	input_correct(char *argv[])
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (argv[1][i] != '\0')
	{
		if ((argv[1][i] != ' ' || (i % 2 == 0))
				&& (argv[1][i] < '1' || argv[1][i] > '4' )
				|| ((i % 2 != 0) && (argv[1][i] != ' ')))
		{
			return (0);
		}
		cont++;
		i++;
	}
	if (cont != 31)
		return (0);
	else if (correct_numbers(argv) == 0)
		return (0);
	else if (check_number_cuatro(argv) == 0)
		return (0);
	return (1);
}
