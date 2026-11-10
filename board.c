
#include <stdlib.h>
#include <unistd.h>
void ft_print(int **board, int n)
{
 int  row;
 int  col;
 char digit;
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
void free_board(int **board, int n)
{
 int i;
i = 0;
while (i < n)
{
 free(board[i]);
 i++;
}
free(board);
}
int **create_board(int n)
{
 int **board;
 int i;
 int j;
board = malloc(sizeof(int *) * n);
if (!board)
 return (NULL);
i = 0;
while (i < n)
{
 board[i] = malloc(sizeof(int) * n);
 if (!board[i])
 {
  free_board(board, i);
  return (NULL);
 }
 j = 0;
 while (j < n)
 {
  board[i][j] = 0;
  j++;
 }
 i++;
}
return (board);
}
