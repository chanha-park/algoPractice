#include <stdio.h>

int	f(int n, int a, int b)
{
	if (n == 1)
		return (b);
	return (f(n - 1, b, (b + 2 * a) % 10007));
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	printf("%d\n", f(n, 1, 1));
	return (0);
}
