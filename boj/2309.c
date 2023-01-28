#include <stdio.h>
#include <stdlib.h>

int	cmp(const void *a, const void *b)
{
	int	x = *(int *)a;
	int	y = *(int *)b;

	if (x > y)
		return (1);
	if (x < y)
		return (-1);
	return (0);
}

int	b[9];

void	print_(int a[], int x, int y)
{
	for (int i = 0; i < 9; i++)
	{
		if (i != x && i != y)
			printf("%d\n", a[i]);
	}
}

int	main(void)
{
	int	a[9];
	int	sum = 0;

	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
	qsort(a, 9, sizeof(int), cmp);
	
	int	i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = i + 1; j < 9; j++)
		{
			if (i != j && (a[i] + a[j] + 100 == sum))
			{
				print_(a, i, j);
				return (0);
			}
		}
	}
	return (0);
}
