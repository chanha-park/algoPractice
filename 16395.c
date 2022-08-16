#include <stdio.h>

int	arr[31][31];

int	comb(int a, int b)
{
	if (b == 0)
		return (1);
	if (b == 1)
		return (a);
	if (b > a - b)
		return (comb(a, a - b));
	if (arr[a][b] == 0)
		arr[a][b] = comb(a - 1, b - 1) + comb(a - 1, b);
	return (arr[a][b]);
}

int	main(void)
{
	int	n, k;

	scanf("%d %d", &n, &k);
	printf("%d\n", comb(n - 1, k - 1));
	return (0);
}
