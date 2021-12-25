/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_dicc_work.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 12:30:57 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/19 12:34:14 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 

#include "rush.h"

char	*key(char *data, int i)
{
	int		j;
	int		aux;
	char	*key;

	aux = i;
	j = 0;
	while (data[aux] != ':')
	{
		aux++;
		j++;
	}
	j++;
	key = (char *) malloc ((j) * sizeof(char));
	j = 0;
	while (data[i] != ':')
	{
		key[j] = data[i];
		i++;
		j++;
	}
	key[j] = '\0';
	return (key);
}

char	*value(char *data, int i)
{
	int		j;
	int		aux;
	char	*value;

	j = 0;
	while (data[i] != ':')
	{
		i++;
	}
	i = i + 2;
	aux = i - 1;
	while (data[aux++] != '\n')
		j++;
	j++;
	value = (char *) malloc ((j) * sizeof(char));
	j = 0;
	while (data[i] != '\n')
	{
		value[j] = data[i];
		i++;
		j++;
	}
	value[j] = '\0';
	return (value);
}

int	next_pos(char *data, int i)
{
	int	pos;
	int	aux;

	aux = i;
	pos = 0;
	while (data[aux] != '\n')
	{
		if (data[aux] == '\0')
			return (aux);
		pos++;
		aux++;
	}
	pos = i + (pos);
	while (!((data[pos] >= '0') && (data[pos] <= '9')))
	{
		if (data[pos] == '\0')
			return (pos);
		pos++;
	}
	return (pos);
}
