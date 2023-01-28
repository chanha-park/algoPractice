#include <stdio.h>

/* int	f(int n, int a, int b, int c)                                                  */
/* {                                                                                  */
/*     if (n == 0)                                                                    */
/*         return (a);                                                                */
/*     if (n == 1)                                                                    */
/*         return (b);                                                                */
/*     if (n == 2)                                                                    */
/*         return (c);                                                                */
/*     return (f(n - 1, b, c, ((long long)3 * c + b - a + 1000000007) % 1000000007)); */
/* }                                                                                  */

int	main(void)
{
	int	n;
	int	a, b, c, tmp;

	scanf("%d", &n);
	a = 0;
	b = 1;
	c = 2;
	while (--n)
	{
		tmp = c;
		c = ((long long)3 * c + b - a + 1000000007) % 1000000007;
		a = b;
		b = tmp;
	}
	printf("%d\n", c);
	return (0);
}
