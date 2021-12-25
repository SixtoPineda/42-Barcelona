/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:27:00 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/08 15:25:59 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	int		x;
	char	letra;

	x = 26;
	letra = 'a';
	while (x != 0)
	{
		write(1, &letra, 1);
		letra ++;
		x --;
	}
}
