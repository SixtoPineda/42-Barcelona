/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:30:23 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/19 22:38:27 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 

#include "rush.h"

int	case_one(char *num, struct s_dicc *dic, int num_keys, int *i)
{
	print_key_num(num[i[0]], dic, num_keys, i[1]);
	if ((i[2] > 1) || ((num[i[0]] == '0') && (num[i[0] + 1] == '0')))
		print_key_post(i[2], dic, num_keys);
	if (i[1] == 1)
		return (3);
	else
		return (i[1]--);
}

int	case_two(char num, struct s_dicc *dic, int num_keys, int *i)
{
	print_key_num(num, dic, num_keys, i[1]);
	if ((num != '0'))
		print_key_post(i[1], dic, num_keys);
	i[1]--;
	return (i[1]);
}

void	print_num(int *i, char *num, struct s_dicc *dic, int num_keys)
{
	while (num[i[0]])
	{
		if (i[1] == 1)
			i[1] = case_one(num, dic, num_keys, i);
		else if (i[1] == 3)
			i[1] = case_two(num[i[0]], dic, num_keys, i);
		else if (i[1] == 2)
		{
			if (num[i[0]] != '1')
				i[1] = print_key_num(num[i[0]], dic, num_keys, i[1]);
			else
			{
				print_key_dec(num[i[0]], num[i[0] + 1], dic, num_keys);
				i[2]--;
				if ((i[2] > 1))
					print_key_post(i[2], dic, num_keys);
				i[1] = 3;
				i[0]++;
			}
		}
		i[2]--;
		i[0]++;
	}
}

void	free_dicc(struct s_dicc *dic, int num_keys)
{
	int	i;

	i = 0;
	while (i < num_keys)
	{
		free(dic[i].key);
		free(dic[i].value);
		i++;
	}
}

void	rush(char *name_file, char *num, int dig)
{
	char			*data;
	int				num_keys;
	struct s_dicc	*dic;
	int				i[3];

	data = NULL;
	dic = NULL;
	data = ors_data(name_file);
	num_keys = extract_num_keys(data);
	dic = store_data(data, num_keys);
	i[0] = zero_case(num, dic, dig);
	dig = dig - i[0];
	i[1] = check_pos_value(dig);
	i[2] = dig;
	print_num(i, num, dic, num_keys);
	write (1, "\n", 1);
	free(data);
	free_dicc(dic, num_keys);
	free(dic);
}
