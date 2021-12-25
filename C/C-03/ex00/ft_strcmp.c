/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:46:33 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/21 14:24:32 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
#include <stdio.h>
#include <string.h>

int		ft_strcmp(char *s1, char *s2);

int		main()
{
	char s1[] = "Nada a ver";
	char s2[] = "Teste de Comparacao";
	char s3[] = "Teste";

	printf("s12: %d, s21: %d, s13: %d, s31: %d, s23: %d, s32: %d", ft_strcmp(s1, s2), ft_strcmp(s2, s1), ft_strcmp(s1, s3), ft_strcmp(s3, s1), ft_strcmp(s2, s3), ft_strcmp(s3, s2));
	printf("\n\ns12: %d, s21: %d, s13: %d, s31: %d, s23: %d, s32: %d", strcmp(s1, s2), strcmp(s2, s1), strcmp(s1, s3), strcmp(s3, s1), strcmp(s2, s3), strcmp(s3, s2));
}
