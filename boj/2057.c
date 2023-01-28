#include <stdio.h>

#define MAX 1000000000000000000ULL

int	main(void)
{
	unsigned long long	a = 1;
	int			b = 1;
	unsigned long long	n;

	while (a < MAX)
	{
		b++;
		a *= b;
	}
	scanf("%llu", &n);
	if (n == 0)
		printf("NO\n");
	else
	{
		while (n > 0 && b > 0)
		{
			if (n >= a)
			{
				n -= a;
			}
			a /= (unsigned long long)b;
			b--;
		}
		if (n == 0 || n == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return (0);
}
