/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:33:55 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/17 20:41:30 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
void	*ft_print_memory(void *addr, unsigned int size);

int		main(void)
{
	char str[] = "Ceci est un test d'affichage de print memory!\nSegFault";
	ft_print_memory(str, 54);
}
int	ft_copystr(char *dest, char *src, unsigned int t)
{
	int	i;
	int	pos;
	int	num_chars;

	num_chars = 0;
	pos = t;
	i = 0;
	while ((src[pos] != '\0') && (i < 16))
	{
		dest[i] = src[pos];
		i++;
		pos++;
		num_chars++;
	}
	dest[i] = '\0';
	return (num_chars);
}

void	ft_putstr_non_printable(char *str, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while ((str[i] != '\0') && (i < size))
	{
		if ((str[i] < 32) || (str[i] > 126))
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_cont_hex(char *str, unsigned int size, unsigned int num_chars)
{
	unsigned int		i;
	char				*aux_hex;
	char				result;

	i = 0;
	aux_hex = "0123456789abcdef";
	while (i < size)
	{
		if (i >= num_chars)
			write(1, "     ", 5);
		else
		{
			result = aux_hex[str[i] / 16];
			write(1, &result, 1);
			result = aux_hex[str[i] % 16];
			write(1, &result, 1);
			result = aux_hex[str[i + 1] / 16];
			write(1, &result, 1);
			result = aux_hex[str[i + 1] % 16];
			write(1, &result, 1);
			write(1, " ", 1);
		}
		i = i + 2;
	}
	write(1, " ", 1);
}

void	ft_print_hex_adress(char *let, char *aux_hex, int j)
{
	unsigned int	*dir;
	int				res[15];
	int				res1;

	while (j++ < 15)
		res[j] = 0;
	dir = (unsigned int *)&let;
	if ((*dir / 1) < 16)
		write(1, &aux_hex[*dir / 1], 1);
	else
	{
		j = 0;
		res[j] = *dir % 16;
		res1 = *dir / 16;
		while (res1 > 16)
		{
			res[j++] = res1 % 16;
			res1 = res1 / 16;
		}
		res[j++] = res1 % 16;
		j = 15;
		while (j-- >= 0)
			write(1, &aux_hex[res[j]], 1);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		i;
	int					num_chars;
	char				*str;
	char				dest[500];
	char				*string;

	str = addr;
	string = (char *)addr;
	if (size == 0)
		return (0);
	i = 0;
	while ((str[i] != '\0') && (i < size))
	{
		num_chars = ft_copystr(dest, str, i);
		ft_print_hex_adress(&string[i], "0123456789abcdef", -1);
		write(1, ": ", 2);
		ft_cont_hex(dest, 16, num_chars);
		ft_putstr_non_printable(dest, size);
		i = i + 16;
	}
	return (addr);
}
