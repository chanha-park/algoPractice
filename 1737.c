#include <stdio.h>
#include <math.h>

long long	f(float n)
{
	if (n <= M_PI)
		return (1);
	return (f(n - 1) + f(n - M_PI));
}

int	main(void)
{
	float	n;

	scanf("%f", &n);
	printf("%lld\n", f(n));
	return (0);
}
