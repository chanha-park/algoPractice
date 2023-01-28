#include <stdio.h>

int	main(void)
{
	int	n, a, b, c;

	scanf("%d", &n);
	a = 0;
	b = 1;
	while (--n)
	{
		c = a + b;
		a = b;
		b = c;
	}
	printf("%d %d\n", a, b);
	return (0);
}
/*                                                    */
/* int	b(int n, int x, int y)                         */
/* {                                                  */
/*     if (n == 0)                                    */
/*         return (0);                                */
/*     if (n == 1)                                    */
/*         return (y);                                */
/*     return (b(n - 1, y, x + y));                   */
/* }                                                  */
/*                                                    */
/* int	main(void)                                     */
/* {                                                  */
/*     int	n;                                         */
/*                                                    */
/*     scanf("%d", &n);                               */
/*     printf("%d %d\n", b(n - 1, 0, 1), b(n, 0, 1)); */
/*     return (0);                                    */
/* }                                                  */
