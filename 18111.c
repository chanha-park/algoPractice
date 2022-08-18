#include <stdio.h>
#include <stdlib.h>

int	cmp(const void *a, const void *b)
{
	int	x = *(int *)a;
	int	y = *(int *)b;

	if (x > y)
		return (-1);
	if (x < y)
		return (1);
	return (0);
}

int	main(void)
{
	int	n, m, size, b;
	int	*arr;
	long long	total_time;
	long long	min_time = 2147483647;
	long long	opt_height;
	long long	curr_block;

	scanf("%d %d %d", &n, &m, &b);
	size = n * m;
	arr = malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
		scanf("%d", &arr[i]);
	qsort(arr, size, sizeof(int), cmp);
	for (int mid = 0; mid < 257; mid++)
	{
		curr_block = b;
		total_time = 0;
		for (int i = 0; i < size; i++)
		{
			if (arr[i] > mid)
				total_time += 2 * (arr[i] - mid);
			else
				total_time += mid - arr[i];
			curr_block += arr[i] - mid;
			if (curr_block < 0)
			{
				total_time = 2147483647;
				break ;
			}
			if (total_time > min_time)
				break ;
		}
		if (total_time < min_time)
		{
			min_time = total_time;
			opt_height = mid;
		}
		else if (total_time == min_time)
		{
			if (opt_height < mid)
				opt_height = mid;
		}
	}
	printf("%lld %lld\n", min_time, opt_height);
	return (0);
}
