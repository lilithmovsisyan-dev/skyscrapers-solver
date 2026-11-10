#include "rush01.h"

static int	is_row_col_valid(int **board, int pos[2], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (i != pos[0] && board[i][pos[1]] == board[pos[0]][pos[1]])
			return (0);
		if (i != pos[1] && board[pos[0]][i] == board[pos[0]][pos[1]])
			return (0);
		i++;
	}
	return (1);
}

static int	num_check(int pos[2], int *sides, int **board, int n)
{
	if (!check_sides_lt(sides, pos, board, n))
		return (0);
	if (pos[1] == n - 1 && !check_sides_lr(sides, pos[0], board, n))
		return (0);
	if (pos[0] == n - 1 && !check_sides_tb(sides, pos[1], board, n))
		return (0);
	return (1);
}

static int	solve_next(int **board, int *sides, int pos[2], int n)
{
	int	next[2];

	next[0] = pos[0];
	next[1] = pos[1] + 1;
	if (next[1] == n)
	{
		next[0]++;
		next[1] = 0;
	}
	return (solve(board, sides, next, n));
}

int	solve(int **board, int *sides, int pos[2], int n)
{
	int	num;

	if (pos[0] >= n)
		return (1);
	num = 1;
	while (num <= n)
	{
		board[pos[0]][pos[1]] = num;
		if (is_row_col_valid(board, pos, n)
			&& num_check(pos, sides, board, n)
			&& solve_next(board, sides, pos, n))
			return (1);
		board[pos[0]][pos[1]] = 0;
		num++;
	}
	return (0);
}
