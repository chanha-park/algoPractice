#include <stdio.h>
#include <stdlib.h>

int	cmp(const void *a, const void *b)
{
	int	x = *(int *)a;
	int	y = *(int *)b;

	if (x < y)
		return (1);
	if (x > y)
		return (-1);
	return (0);
}

int	f(int *arr, int n)
{
	if (n == 1)
		return (*arr);
	if (n == 2)
	{
		int a = arr[0] + arr[1];
		int b = arr[0] * arr[1];
		return (a > b ? a : b);
	}
	if (arr[1] >= 0)
	{
		if (arr[0] + arr[1] < arr[0] * arr[1])
			return (arr[0] * arr[1] + f(arr + 2, n - 2));
		else
			return (arr[0] + f(arr + 1, n - 1));
	}
	int	c = arr[0] + f(arr + 1, n - 1);
	int	d = arr[0] * arr[1] + f(arr + 2, n - 2);
	return (c > d ? c : d);
}

int	main(void)
{
	int	arr[50];
	int	n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	qsort(arr, n, sizeof(int), cmp);
	printf("%d\n", f(arr, n));
	return (0);
}
