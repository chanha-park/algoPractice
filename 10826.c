#include <stdio.h>

int	main(void)
{
	long long	n, a, b, c;

	scanf("%lld", &n);
    if (n == 0)
    {
        printf("0\n");
        return (0);
    }
	a = 0;
	b = 1;
	while (--n > 0)
	{
		c = a + b;
		a = b;
		b = c;
	}
	printf("%lld\n", b);
	return (0);
}
