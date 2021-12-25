/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:57:41 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/19 18:57:44 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 

#include "rush.h"

int	print_key_num(char num, struct s_dicc *dic, int num_keys, int dig)
{
	int		i;
	char	str[3];

	i = 0;
	str[0] = num;
	if (num != '0')
	{
		if (dig == 2)
		{
			str[1] = '0';
			str[2] = '\0';
		}
		else
			str[1] = '\0';
		dig = 1;
		while (i < num_keys)
		{
			if (str_comp(dic[i].key, str, dig) != 0)
			{
				ft_putstr(dic[i].value);
			}
			i++;
		}
	}
	if (dig == 1)
		return (3);
	else
		return (dig--);
}

void	print_key_post(int dig, struct s_dicc *dic, int num_keys)
{
	char	*val_dig;
	int		i;

	val_dig = malloc((dig + 1) * sizeof(char));
	val_dig[0] = '1';
	i = 0;
	while (i < (dig - 1))
	{
		val_dig[i + 1] = '0';
		i++;
	}
	val_dig[i + 1] = '\0';
	i = 0;
	while (i < num_keys)
	{
		if (str_comp(dic[i].key, val_dig, dig) != 0)
		{
			ft_putstr(dic[i].value);
		}
		i++;
	}
	free(val_dig);
}

void	print_key_dec(char num, char num_dos, struct s_dicc *dic, int num_keys)
{
	char	dec[3];
	int		i;

	dec[0] = num;
	dec[1] = num_dos;
	dec[2] = '\0';
	i = 0;
	while (i < num_keys)
	{
		if (str_comp(dic[i].key, dec, 2) != 0)
		{
			ft_putstr(dic[i].value);
		}
		i++;
	}
}
