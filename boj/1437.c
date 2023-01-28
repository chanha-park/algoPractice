#include <stdio.h>
#include <math.h>

int	mod = 10007;
int	arr[13] = {0, 1, 2, 3, 4, 6, 9, 12, 18, 27, 36, 54, 81};

int	max_prod(int n, int p)
{
	if (n <= 12)
		return ((p * arr[n]) % mod);
	return (max_prod(n - 6, (9 * p) % mod));
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	printf("%d\n", max_prod(n, 1));
	return (0);
}
