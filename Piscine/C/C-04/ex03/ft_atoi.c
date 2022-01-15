/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:25:20 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/22 13:54:36 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_spaces(char *str)
{
	int	i;

	i = 0;
	if (str[0] != ' ' && !(str[0] >= '\t' && str[0] <= '\r'))
		return (i);
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+'
			|| ((str[i] >= '0') && (str[i] <= '9')))
		{
			return (i);
		}	
		i++;
	}
	return (i);
}

int	chec_sign(char *str, int *sign, int i)
{
	while (str[i])
	{
		if ((str[i] >= '0') && (str[i] <= '9'))
			return (i);
		if (str[i] == '-')
			*sign = -1 * (*sign);
		if (str[i] == ' ')
			return (-1);
		i++;
	}
	return (i);
}

int	end_number(char *str, int i)
{
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (i - 1);
		i++;
	}
	return (i - 1);
}

int	char_to_int(char *str, int i, int max)
{
	int	num;

	num = 0;
	while (i <= max)
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num);
}

int	ft_atoi(char *str)
{
	int	i;
	int	max;
	int	sign;

	sign = 1;
	if (str[0] == ' ' || str[0] == '-' || (str[0] >= '\t' && str[0] <= '\r')
		|| str[0] == '+' || ((str[0] >= '0') && (str[0] <= '9')))
	{
		i = check_spaces(str);
		i = chec_sign(str, &sign, i);
		if (i < 0)
			return (0);
		max = end_number(str, i);
		return (char_to_int(str, i, max) * sign);
	}
	return (0);
}
