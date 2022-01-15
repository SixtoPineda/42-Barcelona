/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:44:31 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/12 22:02:43 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_row_tt(int matrix[4][4], int subject_rows[2][4], int row);
void	fill_col_tt(int matrix[4][4], int subject_cols[2][4], int col);
void	fill_row_ot(int matrix[4][4], int subject_rows[2][4], int row);
void	fill_col_ot(int matrix[4][4], int subject_cols[2][4], int col);
void	fill_col_ones(int matrix[4][4], int dir, int col);
void	fill_row_ones(int matrix[4][4], int dir, int row);

void	ft_new_matrix(int matrix[4][4], int rows_size)
{
	int	row_num;
	int	item_num;

	row_num = 0;
	while (row_num < rows_size)
	{
		item_num = 0;
		while (item_num < rows_size)
		{
			matrix[row_num][item_num] = 0;
			item_num++;
		}
		row_num++;
	}
}

void	fill_row_m(int matrix[4][4], int dir, int row)
{
	int	i;
	int	k;

	if (dir == 0)
	{
		i = 0;
		while (i < 4)
		{
			matrix[row][i] = (i + 1);
			i++;
		}
	}
	else
	{
		i = 3;
		k = 1;
		while (i > -1)
		{
			matrix[row][i] = k;
			k++;
			i--;
		}
	}
}

void	fill_col_ones(int matrix[4][4], int dir, int col)
{
	if (dir == 0)
		matrix[0][col] = 4;
	else
		matrix[3][col] = 4;
}

void	fill_col_m(int matrix[4][4], int dir, int col)
{
	int	i;
	int	k;

	if (dir == 0)
	{
		i = 0;
		while (i < 4)
		{
			matrix[i][col] = (i + 1);
			i++;
		}
	}
	else
	{
		i = 3;
		k = 1;
		while (i > -1)
		{
			matrix[i][col] = k;
			k++;
			i--;
		}
	}
}

void	fill_cell_dos(int matrix[4][4], int subject_rows[2][4],
			int subject_cols[2][4], int rows_size)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (((subject_rows[0][i] == 2) && (subject_rows[1][i] == 3))
				|| ((subject_rows[0][i] == 3) && (subject_rows[1][i] == 2)))
			fill_row_tt(matrix, subject_rows, i);
		if (((subject_cols[0][i] == 2) && (subject_cols[1][i] == 3))
				|| ((subject_cols[0][i] == 3) && (subject_cols[1][i] == 2)))
			fill_col_tt(matrix, subject_cols, i);
		if (((subject_rows[0][i] == 1) && (subject_rows[1][i] == 2))
				|| ((subject_rows[0][i] == 2) && (subject_rows[1][i] == 1)))
			fill_row_ot(matrix, subject_rows, i);
		if (((subject_cols[0][i] == 1) && (subject_cols[1][i] == 2))
				|| ((subject_cols[0][i] == 2) && (subject_cols[1][i] == 1)))
			fill_col_ot(matrix, subject_cols, i);
		i++;
	}
}
