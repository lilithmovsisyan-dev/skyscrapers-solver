#include "rush01.h"

int	visible_count(int *line, int n, int reverse)
{
	int	i;
	int	index;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < n)
	{
		index = i;
		if (reverse)
			index = n - 1 - i;
		if (line[index] > max)
		{
			max = line[index];
			count++;
		}
		i++;
	}
	return (count);
}

int	partial_line_ok(int *line, int clue, int n)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < n)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count <= clue && count + n - max >= clue);
}
