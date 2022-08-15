#include <stdio.h>

long	p;
long	q;

long	arr[44][44];

long	f(long n, int a, int b)
{
	if (arr[a][b])
		return (arr[a][b]);
	if (n == 0)
		return (1);
	else
	{
		arr[a][b] = f(n / p, a + 1, b);
		arr[a][b] += f(n / q, a, b + 1);
	}
	return (arr[a][b]);
}

int	main(void)
{
	long	n;

	scanf("%ld %ld %ld", &n, &p, &q);
	printf("%ld\n", f(n, 0, 0));
	return (0);
}
