/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 09:55:47 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/17 20:37:10 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdio.h>

int		ft_str_is_printable(char *src);

int		main()
{
	char	c;

	c = 1;
	while (c != 0)
	{
		if ((c < ' ' || c > '~') == ft_str_is_printable(&c))
		{
			printf("Fail for char in decimal: %d\n", (int)c);
			return (0);
		}
		c++;
	}

	printf("Success\n");
}
int	ft_str_is_printable(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if (((*str) < 32) || ((*str) > 126))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
