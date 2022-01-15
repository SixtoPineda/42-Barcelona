/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolvedos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:23:54 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/12 22:02:32 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_row_tt(int matrix[4][4], int subject_rows[2][4], int row)
{
	if (subject_rows[0][row] == 2)
		matrix[row][1] = 4;
	else
		matrix[row][2] = 4;
}

void	fill_col_tt(int matrix[4][4], int subject_cols[2][4], int col)
{
	if (subject_cols[0][col] == 2)
		matrix[1][col] = 4;
	else
		matrix[2][col] = 4;
}

void	fill_row_ot(int matrix[4][4], int subject_rows[2][4], int row)
{
	if (subject_rows[0][row] == 2)
		matrix[row][0] = 3;
	else
		matrix[row][3] = 3;
}

void	fill_col_ot(int matrix[4][4], int subject_cols[2][4], int col)
{
	if (subject_cols[0][col] == 2)
		matrix[0][col] = 3;
	else
		matrix[3][col] = 3;
}

void	fill_row_ones(int matrix[4][4], int dir, int row)
{
	if (dir == 0)
		matrix[row][0] = 4;
	else
		matrix[row][3] = 4;
}
