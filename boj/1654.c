#include <stdio.h>

/* recursion solution */
/* int	bin_search(int *arr, int k, int n, long long left, long long right, int max_len) */
/* {                                                                                    */
/*     long long	mid;                                                                   */
/*     long long	count = 0;                                                             */

/*     if (left >= right)                                                               */
/*         return (max_len);                                                            */
/*     mid = (left + right) / 2;                                                        */
/*     for (int i = 0; i < k; i++)                                                      */
/*     {                                                                                */
/*         count += arr[i] / mid;                                                       */
/*         if (count >= n)                                                              */
/*         {                                                                            */
/*             if (max_len < mid)                                                       */
/*                 max_len = (int)mid;                                                  */
/*             return (bin_search(arr, k, n, mid + 1, right, max_len));                 */
/*         }                                                                            */
/*     }                                                                                */
/*     return (bin_search(arr, k, n, left, mid, max_len));                              */
/* }                                                                                    */

/* iteration solution */
int	bin_search(int *arr, int k, int n)
{
	long long	mid;
	long long	count;
	long long	left;
	long long	right;
	int			max_len;

	left = 1;
	right = 2147483648LL;
	max_len = 1;
	while (left < right)
	{
		mid = (left + right) / 2;
		count = 0;
		for (int i = 0; i < k; i++)
		{
			count += arr[i] / mid;
			if (count >= n)
			{
				if (max_len < mid)
					max_len = (int)mid;
				left = mid + 1;
				break ;
			}
		}
		if (left != mid + 1)
			right = mid;
	}
	return (max_len);
}

int	main(void)
{
	int	k;
	int	n;
	int	arr[10000];
	long long	max_len;

	scanf("%d %d", &k, &n);
	for (int i = 0; i < k; i++)
		scanf("%d", &arr[i]);
	max_len = bin_search(arr, k, n);
	printf("%lld\n", max_len);
	return (0);
}
