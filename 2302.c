#include <stdio.h>

int	fib(int n)
{
	if (n <= 1)
		return (1);
	int	a = 0;
	int	b = 1;
	int	c;

	while (n--)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return (b);
}

int	main(void)
{
	int	n, m;
	int	prod = 1;
	int	t1, t2;

	scanf("%d\n%d", &n, &m);
	t2 = 0;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &t1);
		prod *= fib(t1 - t2 - 1);
		t2 = t1;
	}
	prod *= fib(n - t2);
	printf("%d\n", prod);
	return (0);
}
