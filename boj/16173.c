#include <stdio.h>
#include <stdlib.h>

int	f_(int *arr, int n, int start)
{
	int	right, down;

	if (arr[start] == -1)
		return (1);
	if (arr[start] == 0)
		return (0);
	if (start % n + arr[start] >= n)
		right = 0;
	else
		right = f_(arr, n, start + arr[start]);
	if (start / n + arr[start] >= n)
		down = 0;
	else
		down = f_(arr, n, start + n * arr[start]);
	return (right | down);
}

int	main(void)
{
	int	n;
	int	*arr;

	scanf("%d", &n);
	arr = malloc(sizeof(int) * n * n);
	for (int i = 0; i < n * n; i++)
	{
		scanf("%d", &arr[i]);
	}
	if (f_(arr, n, 0))
		printf("HaruHaru\n");
	else
		printf("Hing\n");
	return (0);
}
