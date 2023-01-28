#include <stdio.h>

int	calc(int m, int n, int x, int y)
{
	int			ret = x;
	int			prod = m * n;

	while (ret <= prod && ret % n != y)
		ret += m;
	if (ret <= prod)
		return (ret);
	return (-1);
}

int	main(void)
{
	int	t;
	int	m, n, x, y;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d %d %d", &m, &n, &x, &y);
		y %= n;
		printf("%d\n", calc(m, n, x, y));
	}
	return (0);
}
