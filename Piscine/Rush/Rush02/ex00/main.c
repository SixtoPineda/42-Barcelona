/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:37:24 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/18 13:47:58 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "rush.h"

int	check_input(char *str)
{
	int	i;

	i = 0;
	if (!((str[0] >= '0') && (str[0] <= '9')))
		return (0);
	return (1);
}

int	num_dig(char *str_num)
{
	int	i;
	int	num_dig;

	i = 0;
	num_dig = 0;
	while (str_num[i])
	{
		if (str_num[i] == '.')
			return (-1);
		if (!((str_num[i] >= '0') && (str_num[i] <= '9')))
		{
			return (num_dig);
		}
		num_dig = num_dig + 1;
		i++;
	}
	return (num_dig);
}

char	*ft_atoi(char *str_num, int *dig)
{
	int			i;
	char		*num;

	i = 0;
	*dig = num_dig(str_num);
	num = malloc (((*dig) + 1) * sizeof(char));
	while (str_num[i])
	{
		if (str_num[i] == '.')
			return (NULL);
		if (!((str_num[i] >= '0') && (str_num[i] <= '9')))
		{
			num[i] = '\0';
			return (num);
		}
		num[i] = str_num[i];
		i++;
	}
	num[i] = '\0';
	return (num);
}

char	*ft_prestart(int pos_arg, char **str, char *argv[], int *dig)
{
	char	*num;

	num = NULL;
	if (pos_arg == 2)
	{
		*str = "numbers.dict";
		if (check_input(argv[1]) == 0)
			return (NULL);
		else
			num = ft_atoi(argv[1], dig);
		return (num);
	}
	else if (pos_arg == 3)
	{
		*str = &(*argv[1]);
		if (check_input(argv[2]) == 0)
			return (NULL);
		else
			num = ft_atoi(argv[2], dig);
		return (num);
	}
	else
		return (num);
}

int	main(int argc, char *argv[])
{
	char	*name_file;
	char	*num;
	int		dig;

	name_file = NULL;
	num = ft_prestart(argc, &name_file, argv, &dig);
	if (num == NULL)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else
	{
		rush(name_file, num, dig);
	}
	free(num);
}
