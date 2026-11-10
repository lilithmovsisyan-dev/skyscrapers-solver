#include "rush01.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_print(int **board, int n)
{
	int		row;
	int		col;
	char	digit;

	row = 0;
	while (row < n)
	{
		col = 0;
		while (col < n)
		{
			digit = board[row][col] + '0';
			write(1, &digit, 1);
			if (col < n - 1)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

void	free_board(int **board, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(board[i]);
		i++;
	}
	free(board);
}

static int	*create_row(int n)
{
	int	*row;
	int	i;

	row = malloc(sizeof(int) * n);
	if (!row)
		return (NULL);
	i = 0;
	while (i < n)
		row[i++] = 0;
	return (row);
}

int	**create_board(int n)
{
	int	**board;
	int	i;

	board = malloc(sizeof(int *) * n);
	if (!board)
		return (NULL);
	i = 0;
	while (i < n)
	{
		board[i] = create_row(n);
		if (!board[i])
		{
			free_board(board, i);
			return (NULL);
		}
		i++;
	}
	return (board);
}
