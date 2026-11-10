
int is_dig(char c, int n)
{
 if (c >= '1' && c <= '0' + n)
  return (1);
 return (0);
}
int is_sides_ok(int *sides, int n)
{
 int i;
i = 0;
while (i < n)
{
 if (sides[i] + sides[n + i] > n + 1)
  return (0);
 if (sides[2 * n + i] + sides[3 * n + i] > n + 1)
  return (0);
 i++;
}
return (1);
}
int is_arg_ok(char *str, int n)
{
 int i;
 int j;
 int sides[36];
i = 0;
j = 0;
while (str[i] && i < 8 * n)
{
 if (i % 2 == 0)
 {
  if (!is_dig(str[i], n))
   return (0);
  sides[j++] = str[i] - '0';
 }
 else if (str[i] != ' ')
 {
  return (0);
 }
 i++;
}
if ((i != 8 * n - 1) || j != 4 * n || !is_sides_ok(sides, n))
 return (0);
return (1);
}
void get_sides(char *str, int *sides)
{
 int i;
i = 0;
while (str[i])
{
 if (i % 2 == 0)
  sides[i / 2] = str[i] - '0';
 i++;
}
}
