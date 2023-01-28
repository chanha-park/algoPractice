#include <stdio.h>
#include <math.h>

int	main(void)
{
	long long	s;
	long long	n;

	scanf("%lld", &s);
	n = -1 + (long long)sqrtl(8 * s + 1);
	n /= 2;
	printf("%lld\n", n);
	return (0);
}
