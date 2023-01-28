#include <stdio.h>

long	fibo(int n, long a, long b)
{
	if (n == 1)
		return (b);
	return (fibo(n - 1, b, a + b));
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	printf("%ld\n", fibo(n, 0, 1));
	return (0);
}
