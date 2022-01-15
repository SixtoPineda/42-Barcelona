/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:11:15 by spineda-          #+#    #+#             */
/*   Updated: 2022/01/10 13:11:16 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((unsigned char)s1[i] == (unsigned char)s2[i])
		&& (s1[i] != '\0') && (s2[i] != '\0') && (i < n))
	{
		i++;
	}
	if (i == n)
		i--;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
