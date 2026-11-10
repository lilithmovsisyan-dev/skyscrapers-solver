

#include <unistd.h>
int  is_arg_ok(char *str, int n);
int  **create_board(int n);
void get_sides(char *str, int *sides);
int  solve(int **board, int *sides, int pos[2], int n);
void ft_print(int **board, int n);
void free_board(int **board, int n);
int ft_error(void)
{
 write(1, "Error\n", 6);
 return (1);
}
int main(int argc, char **argv)
{
 int n;
 int **board;
 int sides[36];
 int pos[2];
n = 4;
if (argc != 2 || !is_arg_ok(argv[1], n))
 return (ft_error());
board = create_board(n);
if (!board)
 return (ft_error());
get_sides(argv[1], sides);
pos[0] = 0;
pos[1] = 0;
if (solve(board, sides, pos, n))
 ft_print(board, n);
else
 ft_error();
free_board(board, n);
return (0);
}
