#include <stdio.h>
#include <math.h>

long long	f_(long long n)
{
	return (((n + 1) / 2) * ((n + 2) / 2));
}

long long	g_(long long h)
{
	int	n = (int)sqrt(4 * h);

	while (f_(n) > h)
		n--;
	while (f_(n) < h)
		n++;
	return (n);
}

int	main(void)
{
	int	x, y;

	scanf("%d %d", &x, &y);
	printf("%lld\n", g_(y - x));
	return (0);
}
