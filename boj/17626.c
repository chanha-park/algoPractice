#include <stdio.h>
#include <math.h>

int	arr[50000];

int	f_(int n)
{
	int	s = (int)sqrt(n);
	int	min = 4;
	int	tmp;

	if (arr[n - 1])
		return (arr[n - 1]);
	if (s * s == n)
		return (1);
	for (int i = s; i >= 1; i--)
	{
		tmp = f_(n - i * i);
		if (min > 1 + tmp)
			min = 1 + tmp;
		if (min == 2)
			break ;
	}
	arr[n - 1] = min;
	return (min);
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	printf("%d\n", f_(n));
	return (0);
}
