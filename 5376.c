#include <stdio.h>
#include <unistd.h>

long	gcd(long a, long b)
{
	if (a < b)
		return (gcd(b, a));
	if (a % b == 0)
		return (b);
	return (gcd(b, a % b));
}

int	count_digit(int a)
{
	int	cnt = 0;

	if (a == 0)
		return (1);
	while (a)
	{
		a /= 10;
		cnt++;
	}
	return (cnt);
}

long	power_ten(int n)
{
	int	ret = 1;

	while (n--)
		ret *= 10;
	return (ret);
}

void	print_finite(long a)
{
	long	b = power_ten(count_digit(a));
	int	g = gcd(a, b);

	printf("%ld/%ld\n", a / g, b / g);
}

void	print_infinite(long a, long b)
{
	long	up;
	long	down;
	int		g;

	if (a)
	{
	up = a * power_ten(count_digit(a) + count_digit(b));
	down = power_ten(count_digit(a) + count_digit(b)) - power_ten(count_digit(a));
	g = gcd(up, down);
	}

	printf("%ld/%ld\n", up / g, down / g);
}

void	print_(char *buff)
{
	long	a = 0;
	long	b = 0;

	while (*buff != '\n' && *buff != '(')
	{
		a = a * 10 + *buff - '0';
		buff++;
	}
	if (*buff == '(')
	{
		buff++;
		while (*buff != ')')
		{
			b = b * 10 + *buff - '0';
			buff++;
		}
	}
	printf("parsed: a = %ld, b = %ld\n", a,b );
	if (b == 0)
		print_finite(a);
	else
		print_infinite(a, b);
}

int	main(void)
{
	int	n;
	char	buff[20];

	scanf("%d", &n);
	while (n--)
	{
		read(0, buff, 20);
		print_(buff + 2);
	}
	return (0);
}
