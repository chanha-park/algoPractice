#include <stdio.h>
#include <stdlib.h>

int	cmp(const void *a, const void *b)
{
	return (*(int *)a > *(int *)b);
}

int	main(void)
{
	int	n;
	int	*arr;

	scanf("%d", &n);
	arr = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	heapsort(arr, n, sizeof(int), cmp);
	long long	sum = 0;
	for (int i = 0; i < n; i++)
		sum += (i + 1 > arr[i] ? (i + 1 - arr[i]) : (arr[i] - i - 1));
	printf("%lld\n", sum);
	return (0);
}
