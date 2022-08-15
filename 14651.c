#include <stdio.h>

long	f(long n, long a)
{
	if (n == 2)
		return (a);
	return (f(n - 1, (3 * a) % 1000000009));
}

int	main(void)
{
	long	n;

	scanf("%ld", &n);
	if (n == 1)
		printf("0\n");
	else
		printf("%ld\n", f(n, 2));
}
