/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:11:17 by syxtyn            #+#    #+#             */
/*   Updated: 2022/01/15 22:11:17 by syxtyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	
*/

static char	obtain_digit(int n, int numdig, int *j, int aux)
{		
	int				dig;
	int				cont;
	int long		numodul;
	int				i;

	i = *j - aux;
	*j = *j + 1;
	numodul = 1;
	cont = 0;
	while (cont < (numdig - 1))
	{
		numodul = numodul * 10;
		cont++;
	}
	cont = 0;
	while (cont <= i)
	{
		numodul = numodul / 10;
		cont++;
	}
	dig = (n % (numodul * 10)) / numodul;
	return (dig + '0');
}

static int	check_int(int n, char *str, int *i, int sign)
{
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		*i = *i + 2;
		return (147483648);
	}
	else if (n == 2147483647)
	{
		str[0] = '2';
		*i = *i + 1;
		return (147483647);
	}
	else if (sign < 0)
	{
		str[0] = '-';
		*i = *i + 1;
		return (-n);
	}
	return (n);
}

static char	*int_to_char(int n, int numdig, int sign)
{
	char	*str;
	int		i;
	int		aux;
	int		new_numdig;

	i = 0;
	aux = 1;
	if (sign < 0)
		numdig++;
	str = (char *) malloc((numdig + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	n = check_int(n, str, &i, sign);
	new_numdig = numdig;
	if (i == 2)
	{
		new_numdig = numdig - i + 1;
		aux = 2;
	}
	while (i < numdig)
		str[i] = obtain_digit(n, new_numdig, &i, aux);
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int	sign;
	int	aux;
	int	numdig;

	numdig = 0;
	sign = 1;
	if (n == 0)
		return ("0");
	else if (n < 0)
		sign = sign * -1;
	aux = n;
	while (aux != 0)
	{
		aux = aux / 10;
		numdig++;
	}
	return (int_to_char(n, numdig, sign));
}

// #include <stdio.h>

// int main()
// {
// 	char *s;
// 	s = ft_itoa(251);
// 	printf("251: %s\n", s);
// 	s = ft_itoa(-251);
// 	printf("-251: %s\n", s);
// 	s = ft_itoa(2147483647);
// 	printf("2147483647: %s\n", s);
// 	s = ft_itoa(-2147483648);
// 	printf("-2147483648: %s\n", s);
// }
