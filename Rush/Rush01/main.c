/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:41:13 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/12 22:01:19 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		input_correct(char *argv[]);
void	ft_new_matrix(int matrix[4][4], int rows_size);
void	fill_row_m(int matrix[4][4], int dir, int row);
void	fill_col_m(int matrix[4][4], int dir, int row);
void	ft_print_matrix(int matrix[4][4], int rows_size);
void	fill_col_ones(int matrix[4][4], int dir, int col);
void	fill_row_ones(int matrix[4][4], int dir, int row);
void	fill_cell_dos(int matrix[4][4], int subject_rows[2][4],
			int subject_cols[2][4], int rows_size);

//Funcion para guardar los argumentos dados

void	store_input(int *cptr, int *rptr, char *argv[])
{
	int	i;
	int	j;
	int	cont_ptr;

	cont_ptr = 0;
	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 4)
		{
			cptr[cont_ptr] = argv[1][(j * 2) + (i * 8)] - '0';
			rptr[cont_ptr] = argv[1][(j * 2) + (i * 8) + 16] - '0';
			cont_ptr++;
			j++;
		}
		i++;
	}
}

//Rellenamos matriz

void	fill_matrix(int *mptr)
{
	int	i;
	int	j;
	int	k;
	int	cont;

	cont = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 5)
			{
				mptr[cont] = k;
				k++;
				cont++;
			}
			j++;
		}
		i++;
	}
}

void	ft_print_matrix(int matrix[4][4], int rows_size)
{
	int		i;
	int		j;
	char	val;

	i = 0;
	while (i < rows_size)
	{
		j = 0;
		while (j < rows_size)
		{
			val = matrix[i][j] + '0';
			write(1, &val, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	sudoku(int subject_rows[2][4], int subject_cols[2][4], int rows_size)
{
	int	matrix[4][4];
	int	i;
	int	j;

	ft_new_matrix(matrix, rows_size);
	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 4)
		{
			if (subject_rows[i][j] == 4)
				fill_row_m(matrix, i, j);
			if (subject_cols[i][j] == 4)
				fill_col_m(matrix, i, j);
			if (subject_rows[i][j] == 1)
				fill_row_ones(matrix, i, j);
			if (subject_cols[i][j] == 1)
				fill_col_ones(matrix, i, j);
			j++;
		}
		i++;
	}
	fill_cell_dos(matrix, subject_rows, subject_cols, rows_size);
	ft_print_matrix(matrix, rows_size);
}

//-----------------MAIN----------------------

int	main(int argc, char *argv[])
{
	int	subject_cols[2][4];
	int	subject_rows[2][4];
	int	rows_size;
	int	*cptr;
	int	*rptr;

	rows_size = 4;
	cptr = &subject_cols[0][0];
	rptr = &subject_rows[0][0];
	if (input_correct(argv) != 0)
	{
		store_input(cptr, rptr, argv);
		sudoku(subject_rows, subject_cols, rows_size);
		return (1);
	}
	write(1, "Error\n", 6);
	return (0);
}
