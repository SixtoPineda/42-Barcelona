/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:16:39 by syxtyn            #+#    #+#             */
/*   Updated: 2022/01/15 22:16:39 by syxtyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
	Reserva con malloc(3) memoria para devolver una
	string nueva basada en la string ’s’.
	La nueva string empieza en el índice ’start’ y
	tiene una longitud máxima ’len’.
 */

static char	*strcpylen(char *str, char const *s, unsigned int start, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size;

	if (s[0] == 0 || len == 0 || start > ft_strlen(s))
	{
		str = (char *) malloc(1 * sizeof(char));
		return (str);
	}
	if (len > ft_strlen(s))
		size = ft_strlen(s) + 1 - start;
	else if (ft_strlen(s) - start < len)
		size = (ft_strlen(s) - start) + 1;
	else
		size = len + 1;
	str = (char *) malloc((size) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str = strcpylen(str, s, start, size - 1);
	return (str);
}

/* 

int main()
{
	// res = test_single_substr("hola", 0, -1, "hola") && res;

	printf("%s\n\n",ft_substr("hola", 0, -1));
} */