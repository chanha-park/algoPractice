#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void	f_(int *arr, int i)
{
	int	sq = (int)sqrt(i + 1);
	int	min = i + 1;

	if (sq * sq == i + 1)
	{
		arr[i] = 1;
		return ;
	}
	for (int j = 1; j <= sq; j++)
	{
		if (min > 1 + arr[i - j * j])
			min = 1 + arr[i - j * j];
		if (min == 2)
			break ;
	}
	arr[i] = min;
}

int	main(void)
{
	int	n;
	int	*arr;

	scanf("%d", &n);
	arr = malloc(sizeof(int) * n);
	arr[0] = 1;
	arr[1] = 2;
	for (int i = 2; i < n; i++)
		f_(arr, i);
	printf("%d\n", arr[n - 1]);
	return (0);
}
