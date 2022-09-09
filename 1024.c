#include <stdio.h>

void	print_(int n, int l)
{
	int	count = l;

	n -= (l * (l - 1)) / 2;
	while ((n > 0) && (n % count != 0))
	{
		n -= count;
		count++;
	}
	if (n >= 0 && count <= 100)
	{
		for (int i = 0; i < count; i++)
			printf("%d ", n / count + i);
		printf("\n");
	}
	else
		printf("-1\n");
}

int	main(void)
{
	int	n, l;

	scanf("%d %d", &n, &l);
	print_(n, l);
	return (0);
}
