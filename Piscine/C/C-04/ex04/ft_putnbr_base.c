/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:30:21 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/21 20:41:49 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(long int nb, char *base, int len_base)
{
	if (nb >= len_base)
	{
		print_num(nb / len_base, base, len_base);
	}
	write(1, &base[nb % len_base], 1);
}

int	check_base(char *base)
{	
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| (base[i] >= '\t' && base[i] <= '\r'))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i == 0 || i == 1)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			len_base;
	long int	aux;
	int			dig;

	len_base = 0;
	dig = 0;
	aux = nbr;
	if (check_base(base) != 0)
	{
		while (base[len_base])
			len_base++;
		if (aux < 0)
		{
			write(1, "-", 1);
			aux = -aux;
		}
		print_num(aux, base, len_base);
	}
}
