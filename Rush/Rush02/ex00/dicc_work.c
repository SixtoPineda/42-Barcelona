/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dicc_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:26:18 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/19 12:35:09 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 

#include "rush.h"

char	*ors_data(const char *name_file)
{
	int		open_file;	
	int		file_data;
	char	*buf;
	char	*str_data;
	int		i;

	i = -1;
	open_file = open(name_file, O_RDONLY);
	if (open_file < 0)
		return (0);
	buf = (char *) malloc (2000 * sizeof (char));
	file_data = read(open_file, buf, 2000);
	if (file_data < 0)
		return (0);
	str_data = (char *) malloc ((file_data + 1) * sizeof (char));
	while (i++ < file_data)
		str_data[i] = buf[i];
	str_data[i] = '\0';
	free(buf);
	close(open_file);
	return (str_data);
}

struct s_dicc	*store_data(char *data, int num_keys)
{
	int				i;
	int				i_dic;
	struct s_dicc	*dic;

	i_dic = 0;
	i = 0;
	dic = malloc(num_keys * sizeof * dic);
	while (data[i] != '\0')
	{
		dic[i_dic].key = key(data, i);
		dic[i_dic].value = value(data, i);
		i = next_pos(data, i);
		i_dic++;
	}
	return (dic);
}

int	extract_num_keys(char *data)
{
	int	i;
	int	num_keys;

	i = 0;
	num_keys = 0;
	while (data[i])
	{
		if (data[i] == '\n')
			num_keys++;
		i++;
	}
	return (num_keys);
}

int	zero_case(char *num, struct s_dicc *dic, int dig)
{
	int	i;

	if ((dig == 1) && (num[0] == '0'))
		ft_putstr(dic[0].value);
	else if (num[0] == '0')
	{
		i = 0;
		while (num[i] == '0')
			i++;
		return (i);
	}
	else
	{
		i = 0;
		while (num[i])
		{
			if (num[i] != '0')
				return (0);
			i++;
		}
	}
	return (0);
}

int	check_pos_value(int dig)
{
	if (dig % 3 == 0)
		return (3);
	else if ((dig - 1) % 3 == 0)
		return (1);
	else
		return (2);
}
