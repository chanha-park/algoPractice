#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int	cmp(const void *a, const void *b)
{
	return (*(int *)a > *(int *)b);
}

int	main(void)
{
	int	n;
	int	*arr;
	int	freq[8001] = {0};
	long	min = 2147483648;
	long	max = -2147483648;
	int	mode = 2147483647;
	long long	sum = 0;

	scanf("%d", &n);
	arr = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		freq[arr[i] + 4000] += 1;
		if (mode == 2147483647 || freq[arr[i] + 4000] > freq[mode + 4000])
			mode = arr[i];
		if (min > arr[i])
			min = arr[i];
		if (max < arr[i])
			max = arr[i];
		sum += arr[i];
	}
	qsort(arr, n, sizeof(int), cmp);
	if (sum >= 0)
		sum = (int)((double)sum / n + 0.5);
	else
		sum = (int)((double)sum / n - 0.5);
	printf("%lld\n", sum);
	printf("%d\n", arr[n / 2]);
	printf("%d\n", mode);
	printf("%ld\n", max - min);
	return (0);
}
