#include "rush01.h"

int	check_sides_lr(int *sides, int row, int **board, int n)
{
	return (visible_count(board[row], n, 0) == sides[2 * n + row]
		&& visible_count(board[row], n, 1) == sides[3 * n + row]);
}

int	check_sides_tb(int *sides, int col, int **board, int n)
{
	int	line[BOARD_SIZE];
	int	i;

	i = 0;
	while (i < n)
	{
		line[i] = board[i][col];
		i++;
	}
	return (visible_count(line, n, 0) == sides[col]
		&& visible_count(line, n, 1) == sides[n + col]);
}

int	check_sides_lt(int *sides, int pos[2], int **board, int n)
{
	int	line[BOARD_SIZE];
	int	i;

	if (!partial_line_ok(board[pos[0]], sides[2 * n + pos[0]], n))
		return (0);
	i = 0;
	while (i < n)
	{
		line[i] = board[i][pos[1]];
		i++;
	}
	return (partial_line_ok(line, sides[pos[1]], n));
}
