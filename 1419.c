#include <stdio.h>

// kx + k(k-1)d/2

int	get_count(int l, int r, int k)
{
	int	count;

	if (k == 2)
	{
		count = r - l + 1;
		int	arr[2] = {1, 2};
		for (int i = 0; i < 2; i++)
		{
			if (l <= arr[i] && arr[i] <= r)
				count--;
		}
		return (count > 0 ? count : 0);
	}
	else if (k == 3)
	{
		count = r / 3 - ((l - 1) / 3);
		if (l <= 3 && 3 <= r)
			count--;
		return (count > 0 ? count : 0);
	}
	else if (k == 4)
	{
		count = r / 2 - ((l - 1) / 2);
		int	arr[5] = {2, 4, 6, 8, 12};
		for (int i = 0; i < 5; i++)
		{
			if (l <= arr[i] && arr[i] <= r)
				count--;
		}
		return (count > 0 ? count : 0);
	}
	else
	{
		count = r / 5 - ((l - 1) / 5);
		if (l <= 5 && 5 <= r)
			count--;
		if (l <= 10 && 10 <= r)
			count--;
	}
	return (count);
}

int	main(void)
{
	int	l, r, k;
	int	count;

	scanf("%d %d %d", &l, &r, &k);
	count = get_count(l, r, k);
	printf("%d\n", count);
	return (0);
}
/*                                              */
/*                                              */
/* k = 2 ~ 5;                                   */
/* 2, 3, 4, 5;                                  */
/* 1, 3, 6, 10;                                 */
/*                                              */
/* 2x + d; -> 3, 5, 6                           */
/* 3x + 3d; -> 6, 9, 12, ...                    */
/* 4x + 6d; -> 10, 14, 16, 18, 20, 22, 24, 26,  */
/* 5x + 10d; -> 15, 20, 25, 30                  */
