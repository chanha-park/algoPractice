#include <stdio.h>

int	f(int n, int a, int b)
{
	if (n == 1)
		return (b);
	return (f(n - 1, b, (a + 2 * b) % 9901));
}

int	main(void)
{
	int	n;
	scanf("%d", &n);
	printf("%d\n", f(n, 1, 3));
	return (0);
}
