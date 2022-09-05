#include <stdio.h>

int	f(int n, int a, int b, int c)
{
	if (n == 0)
		return (a);
	if (n == 1)
		return (b);
	if (n == 2)
		return (c);
	return (f(n - 1, b, c, ((long long)3 * c + b - a + 1000000007) % 1000000007));
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	printf("%d\n", f(n, 1, 2, 7));
	return (0);
}
