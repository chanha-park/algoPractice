#include <stdio.h>
#include <stdlib.h>

int	bin_search(int *arr, int n, int m, int left, int right, int max_height)
{
	int	mid;
	long long	sum = 0;
	long long	diff;

	if (left >= right)
		return (max_height);
	mid = (left + right) / 2;
	for (int i = 0; i < n; i++)
	{
		diff = arr[i] - mid;
		if (diff > 0)
			sum += diff;
		if (sum >= m)
		{
			if (max_height < mid)
				max_height = mid;
			return (bin_search(arr, n, m, mid + 1, right, max_height));
		}
	}
	return (bin_search(arr, n, m, left, mid, max_height));
}

int	main(void)
{
	int	n;
	int	m;
	int	arr[1000000];
	int	max_height;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	max_height = bin_search(arr, n, m, 0, 1000000000, 0);
	printf("%d\n", max_height);
	return (0);
}
