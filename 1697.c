#include <stdio.h>

int	arr[200001];

int	f_(int n, int k)
{
	if (n >= k)
	{
		arr[n] = n - k;
		return (arr[n]);
	}
	if (k - n == 1 || n * 2 == k)
		return (1);
	if (arr[n] == 0)
	{
		int	a = 1 + f_(n + 1, k);
		int	b;
		if (n)
			b = 1 + f_(2 * n, k);
		else
			b = 2147483647;
		int	c = 1 + (k % 2) + f_(n, (k + 1) / 2);

		if (a > b)
			a = b;
		if (a > c)
			a = c;
		arr[n] = a;
	}
	return (arr[n]);
}

int	main(void)
{
	int	n, k;

	scanf("%d %d", &n, &k);
	printf("%d\n", f_(n, k));
	return (0);
}
