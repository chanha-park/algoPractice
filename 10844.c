#include <stdio.h>

int	ft_whole(int n)
{
	int	s;

	s = 1;
	while (n-- > -2)
	{
		s = s << 1;
		if (s >= 1000000000)
			s -= 1000000000;
	}
	return (s + 2);
}

int	ft_comb(int n, int a, int b)
{
	int	num;

	if (n == 1)
		return (b);
	num = 2 * b + 4 * (n - 1) * a;
	num /= (n + 1);
	return (ft_comb(n - 1, b, num));
}

int	ft_part(int n)
{
	return (ft_comb(n, 1, 1));
}

int	ft_stair(int n)
{
	return (ft_whole(n) - ft_part(n - 1));
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	printf("%d", ft_stair(n));
	return (0);
}
