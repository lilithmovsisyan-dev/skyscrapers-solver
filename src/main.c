#include "rush01.h"
#include <unistd.h>

int	ft_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

static int	run_solver(int **board, int *sides, int n)
{
	int	pos[2];
	int	status;

	pos[0] = 0;
	pos[1] = 0;
	status = 0;
	if (solve(board, sides, pos, n))
		ft_print(board, n);
	else
		status = ft_error();
	free_board(board, n);
	return (status);
}

int	main(int argc, char **argv)
{
	int	**board;
	int	sides[4 * BOARD_SIZE];

	if (argc != 2 || !is_arg_ok(argv[1], BOARD_SIZE))
		return (ft_error());
	board = create_board(BOARD_SIZE);
	if (!board)
		return (ft_error());
	get_sides(argv[1], sides);
	return (run_solver(board, sides, BOARD_SIZE));
}
