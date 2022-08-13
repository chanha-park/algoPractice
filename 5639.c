#include <stdio.h>

int	bsearch(int *arr, int start, int end, int target)
{
	int	left = start;
	int	right = end;
	int	mid, ans;

	if (start >= end)
		return (end);
	ans = right;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (arr[mid] < target)
			left = mid + 1;
		else
		{
			ans = right;
			right = mid;
		}
	}
	return (ans);
}

void	print_post(int *arr, int head, int tail)
{
	int	root = arr[head];
	int	mid = head + 1;

	mid = bsearch(arr, head + 1, tail, root);
	if (head + 2 <= mid)
		print_post(arr, head + 1, mid - 1);
	if (mid <= tail)
		print_post(arr, mid, tail);
	printf("%d\n", root);
}

int	main(void)
{
	int	arr[10001];
	int	head = 0;
	int	tail = 0;

	while (1)
	{
		if (scanf("%d", &arr[tail]) > 0)
			tail++;
		else
			break ;
	}
	print_post(arr, head, tail - 1);
	return (0);
}
