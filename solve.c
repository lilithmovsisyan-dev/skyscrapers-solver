
int check_sides_lr(int *sides, int pos[2], int **board, int n);
int check_sides_tb(int *sides, int pos[2], int **board, int n);
int check_sides_lt(int *sides, int pos[2], int **board, int n);
int solve_next(int **board, int *sides, int pos[2], int n);
int is_ok_sudoku(int col, int row, int **board, int n)
{
 int i;
i = 0;
while (i < n)
{
 if (i != row && board[i][col] == board[row][col])
  return (0);
 if (i != col && board[row][i] == board[row][col])
  return (0);
 i++;
}
return (1);
}
int num_check(int pos[2], int *sides, int **board, int n)
{
 if (!check_sides_lt(sides, pos, board, n))
  return (0);
 if (pos[1] == n - 1 && check_sides_lr(sides, pos, board, n) == 0)
  return (0);
 if (pos[0] == n - 1 && check_sides_tb(sides, pos, board, n) == 0)
  return (0);
 return (1);
}
int solve(int **board, int *sides, int pos[2], int n)
{
 int num;
if (pos[0] >= n)
 return (1);
num = 1;
while (num <= n)
{
 board[pos[0]][pos[1]] = num;
 if (is_ok_sudoku(pos[1], pos[0], board, n)
  && num_check(pos, sides, board, n)
  && solve_next(board, sides, pos, n))
  return (1);
 board[pos[0]][pos[1]] = 0;
 num++;
}
return (0);
}
int solve_next(int **board, int *sides, int pos[2], int n)
{
 int next[2];
next[0] = pos[0];
next[1] = pos[1] + 1;
if (next[1] == n)
{
 next[0]++;
 next[1] = 0;
}
return (solve(board, sides, next, n));
}
