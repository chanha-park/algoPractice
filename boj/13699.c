#include <stdio.h>

long long	arr[36];

long long	t_(int n)
{
	long long	sum = 0;

	if (n == 0)
		return (1);
	if (arr[n] == 0)
	{
		for (int i = 0; i < n; i++)
			sum += t_(i) * t_(n - i - 1);
		arr[n] = sum;
	}
	return (arr[n]);
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	printf("%lld\n", t_(n));
	return (0);
}
