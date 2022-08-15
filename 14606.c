#include <stdio.h>
/*                                                */
/* int	sum_halfs(int n)                           */
/* {                                              */
/*     int	sum = 0;                               */
/*                                                */
/*     n >>= 1;                                   */
/*     while (n)                                  */
/*     {                                          */
/*         sum += n;                              */
/*         n >>= 1;                               */
/*     }                                          */
/*     return (sum);                              */
/* }                                              */
/*                                                */
/* int	max_fun(int n, int a)                      */
/* {                                              */
/*     if (n <= 2)                                */
/*         return (a);                            */
/*     return (max_fun(n - 1, a + sum_halfs(n))); */
/* }                                              */
/*                                                */
int	max_fun(int n)
{
	if (n <= 1)
		return (0);
	if (n == 2)
		return (1);
	return ((n / 2) * (n - n / 2) + max_fun(n / 2) + max_fun(n - n / 2));
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	printf("%d\n", max_fun(n));
	return (0);
}
