#include <stdio.h>

int	f(int n, int a, int b)
{
	if (n == 1)
		return (a);
	if (n == 2)
		return (b);
	return (f(n - 1, b, 4 * b - a));
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	if (n % 2)
		printf("0\n");
	else
		printf("%d\n", f(n >> 1, 3, 11));
	return (0);
}

/* 1		0                                        */
/* 2		3                                        */
/* 3		0                                        */
/* 4		f(2) * f(2) + 2 = 11                     */
/* 5		0                                        */
/* 6		f(2) * f(4) + 2 * f(2) + 2               */
/* 7		0                                        */
/* 8		f(2) * f(6) + 2 * f(4) + 2 * f(2) + 2    */



/* 01166114                                    */
/* 03344334                                    */
/* 22552255                                    */


/* f(8) - f(6) = 3 * (f(6) - f(4)) + 2 * f(4); */
/* f(8) = 4 * f(6) - f(4);                     */
