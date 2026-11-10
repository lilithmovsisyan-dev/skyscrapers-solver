#include "rush01.h"

static int	is_sides_ok(int *sides, int n)
{
	int	i;

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

int	is_arg_ok(char *str, int n)
{
	int	i;
	int	sides[4 * BOARD_SIZE];

	i = 0;
	while (str[i] && i < 8 * n - 1)
	{
		if (i % 2 == 0)
		{
			if (str[i] < '1' || str[i] > '0' + n)
				return (0);
			sides[i / 2] = str[i] - '0';
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	if (i != 8 * n - 1 || str[i] != '\0')
		return (0);
	return (is_sides_ok(sides, n));
}

void	get_sides(char *str, int *sides)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i % 2 == 0)
			sides[i / 2] = str[i] - '0';
		i++;
	}
}
