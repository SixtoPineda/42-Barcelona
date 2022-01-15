/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:54:21 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/08 15:26:27 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_print_reverse_alphabet(void)
{
	int		x;
	char	letra;

	x = 26;
	letra = 'z';
	while (x != 0)
	{
		write(1, &letra, 1);
		letra --;
		x --;
	}
}
