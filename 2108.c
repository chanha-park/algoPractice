#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int	cmp(const void *a, const void *b)
{
	int	x = *(int *)a;
	int	y = *(int *)b;

	if (x > y)
		return (1);
	else if (x < y)
		return (-1);
	else
		return (0);
}

int	main(void)
{
	int	n;
	int	*arr;
	int	freq[8001];
	long	min = 2147483648;
	long	max = -2147483648;
	int	max_freq = 0;
	int	max_freq_num = 0;
	int	flag = 0;
	long long	sum = 0;

	scanf("%d", &n);
	arr = malloc(sizeof(int) * n);
	memset(freq, 0, sizeof(int) * 8001);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		freq[arr[i] + 4000] += 1;
		if (min > arr[i])
			min = arr[i];
		if (max < arr[i])
			max = arr[i];
		sum += arr[i];
	}
	qsort(arr, n, sizeof(int), cmp);
	for (int i = -4000; i <= 4000; i++)
	{
		if (max_freq < freq[i + 4000])
		{
			max_freq = freq[i + 4000];
			max_freq_num = i;
			flag = 0;
		}
		else if (flag == 0 && max_freq == freq[i + 4000])
		{
			flag = 1;
			max_freq_num = i;
		}
	}
	if (sum >= 0)
		sum = (int)((double)sum / n + 0.5);
	else
		sum = (int)((double)sum / n - 0.5);
	printf("%lld\n", sum);
	printf("%d\n", arr[n / 2]);
	printf("%d\n", max_freq_num);
	printf("%ld\n", max - min);
	return (0);
}
