

int check_sides_lr(int *sides, int pos[2], int **board, int n)
{
 int i;
 int max[2];
 int check[2];
i = 0;
max[0] = 0;
max[1] = 0;
check[0] = 0;
check[1] = 0;
while (i < n)
{
 if (board[pos[0]][i] > max[0])
  check[0]++;
 if (board[pos[0]][i] > max[0])
  max[0] = board[pos[0]][i];
 if (board[pos[0]][n - 1 - i] > max[1])
  check[1]++;
 if (board[pos[0]][n - 1 - i] > max[1])
  max[1] = board[pos[0]][n - 1 - i];
 i++;
}
return (check[0] == sides[2 * n + pos[0]]
 && check[1] == sides[3 * n + pos[0]]);
}
int check_sides_lt(int *sides, int pos[2], int **board, int n)
{
 int i;
 int max[2];
 int check[2];
i = 0;
max[0] = 0;
max[1] = 0;
check[0] = 0;
check[1] = 0;
while (i < n)
{
 if (board[pos[0]][i] > max[0])
  check[0]++;
 if (board[pos[0]][i] > max[0])
  max[0] = board[pos[0]][i];
 if (board[i][pos[1]] > max[1])
  check[1]++;
 if (board[i][pos[1]] > max[1])
  max[1] = board[i][pos[1]];
 i++;
}
return (check[0] <= sides[2 * n + pos[0]]
 && check[0] + n - max[0] >= sides[2 * n + pos[0]]
 && check[1] <= sides[pos[1]]
 && check[1] + n - max[1] >= sides[pos[1]]);
}
int check_sides_tb(int *sides, int pos[2], int **board, int n)
{
 int i;
 int max[2];
 int check[2];
i = 0;
max[0] = 0;
max[1] = 0;
check[0] = 0;
check[1] = 0;
while (i < n)
{
 if (board[i][pos[1]] > max[0])
  check[0]++;
 if (board[i][pos[1]] > max[0])
  max[0] = board[i][pos[1]];
 if (board[n - 1 - i][pos[1]] > max[1])
  check[1]++;
 if (board[n - 1 - i][pos[1]] > max[1])
  max[1] = board[n - 1 - i][pos[1]];
 i++;
}
return (check[0] == sides[pos[1]] && check[1] == sides[n + pos[1]]);
}
