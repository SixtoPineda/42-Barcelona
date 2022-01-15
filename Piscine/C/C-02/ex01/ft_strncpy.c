/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 09:29:10 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/17 20:33:52 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int		main()
{
	int i;
	char dest[] = "Epic fail !!!!!";
	char src[] = "Success";
	printf("%s\n%s\n%s\n", src, ft_strncpy(dest, src, 15), dest);
	i = 9;
	while (i < 15)
	{
		if (dest[i] != '\0')
		{
			printf("FAIL! Remainder of dst must be filled with `\\0' characters, got %c (\\%x) at pos %d\n", dest[i], dest[i], i);
			return (1);
		}
		i++;
	}
	return (0);
}
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	num_chars;

	i = 0;
	num_chars = 0;
	while (src[num_chars] != '\0')
		num_chars++;
	while (i < n)
	{
		if (i > num_chars)
			dest[i] = '\0';
		else
			dest[i] = src[i];
		i++;
	}
	return (dest);
}
