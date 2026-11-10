#ifndef RUSH01_H
# define RUSH01_H

# define BOARD_SIZE 4

int		ft_error(void);
int		is_arg_ok(char *str, int n);
void	get_sides(char *str, int *sides);
int		**create_board(int n);
void	free_board(int **board, int n);
void	ft_print(int **board, int n);
int		solve(int **board, int *sides, int pos[2], int n);
int		check_sides_lr(int *sides, int row, int **board, int n);
int		check_sides_tb(int *sides, int col, int **board, int n);
int		check_sides_lt(int *sides, int pos[2], int **board, int n);
int		visible_count(int *line, int n, int reverse);
int		partial_line_ok(int *line, int clue, int n);

#endif
