/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:19:13 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/17 20:41:01 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <unistd.h>

void	ft_putstr_non_printable(char *src);

void	ft_putstr(char *str)
{
	int l;

	l = 0;
	while (str[l])
	{
		l++;
	}
	write(1, str, l);
}

int		main()
{
	char c[] = "Coucou\ntu vas bien ?";
	ft_putstr("Coucou\\0atu vas bien ?:");
	ft_putstr_non_printable(c);
	char d[] = "\x81\xbe";
	ft_putstr("\n\\81\\be:");
	ft_putstr_non_printable(d);
}
void	ft_ascii_to_hex(char str)
{
	char	*aux_hex;
	char	result;

	aux_hex = "0123456789abcdef";
	write(1, "\\", 1);
	result = aux_hex[(unsigned char)str / 16];
	write(1, &result, 1);
	result = aux_hex[(unsigned char)str % 16];
	write(1, &result, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 32) || (str[i] > 126))
		{
			ft_ascii_to_hex(str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
