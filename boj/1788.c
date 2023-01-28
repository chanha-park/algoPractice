#include <stdio.h>

#define MOD 1000000000

int	fibo(int n)
{
	int	a = 0;
	int	b = 1;
	int	c;

	while (n--)
	{
		c = (a + b) % MOD;
		a = b;
		b = c;
	}
	return (a);
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	if (n == 0)
		printf("0\n0\n");
	else if (n > 0)
		printf("1\n%d\n", fibo(n));
	else if (n % 2 == 0)
		printf("-1\n%d", fibo(-n));
	else
		printf("1\n%d\n", fibo(-n));
	return (0);
}
