/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:42:48 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/22 11:54:34 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && ((s1[i] != '\0') && (s2[i] != '\0')))
	{
		i++;
	}
	if ((s1[i] == '\0') && (s2[i] != '\0'))
		return (s1[i] - s2[i]);
	else if ((s1[i] != '\0') && (s2[i] == '\0'))
		return (s1[i] - s2[i]);
	else
		return (s1[i] - s2[i]);
}

void	ft_swap(int *a, int *b)
{
	int	sw;

	sw = *a;
	*a = *b;
	*b = sw;
}

void	printarg(char **argv, int *i, int argc)
{
	int	j;
	int	w;

	j = 1;
	while (j < argc)
	{
		w = 0;
		while (argv[i[j]][w])
		{
			write(1, &argv[i[j]][w], 1);
			w++;
		}
		write(1, "\n", 1);
		j++;
	}
}

int	main(int argc, char **argv)
{
	int	i[200];
	int	j;
	int	w;

	j = -1;
	if (argc > 1)
	{
		while (j++ < argc)
			i[j] = (j);
		j = 1;
		while (j < (argc))
		{
			w = j;
			while (w < (argc))
			{
				if (ft_strcmp(argv[i[j]], argv[i[w]]) > 0)
					ft_swap(&i[j], &i[w]);
				w++;
			}
			j++;
		}
		j = -1;
		printarg(argv, i, argc);
	}
}
