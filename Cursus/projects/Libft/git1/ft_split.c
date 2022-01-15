/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:22:09 by syxtyn            #+#    #+#             */
/*   Updated: 2022/01/15 22:22:09 by syxtyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	- First we obtain the number of strings that are inside "s".
	- get_pos: to get the inicial (i) and final (final) position 
		of the string inside "s"
	- Verify if we are at the end of the string "s"
	- get_string: we get the string to add to our matrix
		using the inicial and final position of "s"
	- The array should end with NULL
*/

static int	num_strs(char const *s, char c)
{
	int		num_str;
	int		i;

	i = 0;
	num_str = 0;
	while (s[i])
	{
		while ((char)s[i] == c)
			i++;
		if ((char)s[i] != '\0')
			num_str++;
		else if ((char)s[i] == '\0')
			break ;
		while ((char)s[i] != c && (char)s[i] != '\0')
			i++;
	}
	return (num_str);
}

static int	get_pos(int *i, char const *s, char c)
{
	int	final;

	while (s[*i] && (char)s[*i] == c)
		*i = *i + 1;
	if ((char)s[*i] == '\0')
		return (-1);
	final = *i;
	while ((char)s[final] != c && s[final])
		final++;
	return (final);
}

static char	*get_string(int i, int final, char const *s)
{
	char	*str;
	int		aux;

	aux = 0;
	str = (char *) malloc((final - i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i < final)
	{
		str[aux] = (char)s[i];
		i++;
		aux++;
	}
	str[aux] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		num_str;
	char	**m;
	int		final;
	int		i;

	m = NULL;
	i = 0;
	final = 0;
	num_str = num_strs(s, c);
	m = (char **)malloc((num_str + 1) * sizeof(char *));
	if (m == NULL)
		return (NULL);
	num_str = 0;
	while (s[i])
	{
		final = get_pos(&i, s, c);
		if (final < 0)
			break ;
		m[num_str++] = get_string(i, final, s);
		i = final;
	}
	m[num_str++] = NULL;
	return (m);
}

// #include <stdio.h>

// int main()
// {
// 	char **s;
// 	s = ft_split("  hola que tal  ", ' ');
// 	if (s[2][3] == '\0')
// 		printf("%s", s[2]);
// }
