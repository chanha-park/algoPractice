#include <stdio.h>

int	main(void)
{
	int	n, tmp, m;
	int	arr[10] = {0};

	scanf("%d", &n);
	m = 0;
	while (n)
	{
		tmp = n % 10;
		n /= 10;
		if (tmp == 6 || tmp == 9)
		{
			arr[6] += 1;
			if (arr[6] > 2 * m)
				m++;
		}
		else
		{
			arr[tmp] += 1;
			if (arr[tmp] > m)
				m++;
		}
	}
	printf("%d\n", m);
	return (0);
}
