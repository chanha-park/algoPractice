#include <stdio.h>

long long f_(int s, int k, long long p)
{
	if (k == 1)
		return (s * p);
	if (s == k)
		return (p);
	int	a = s / k;
	return (f_(s - a, k - 1, a * p));
}

int	main(void)
{
	int	s, k;

	scanf("%d %d", &s, &k);
	printf("%lld\n", f_(s, k, 1));
	return (0);
}
