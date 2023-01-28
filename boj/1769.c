#include <stdio.h>

int	sum(char *s, int *len)
{
	int	r = 0;
	while (*s)
	{
		r += *s++ - '0';
		*len += 1;
	}
	return (r);
}

int	sum_i(int s)
{
	int	r = 0;

	while (s > 0)
	{
		r += s % 10;
		s /= 10;
	}
	return (r);
}

int	main(void)
{
	char	str[1000001];
	int	x;
	int	count = 0;

	scanf("%s", str);
	x = sum(str, &count);
	if (count == 1)
		printf("0\n%s\n", ((*str - '0') % 3 == 0) ? "YES" : "NO");
	else
	{
		count = 1;
		while (x > 9)
		{
			x = sum_i(x);
			count++;
		}
		printf("%d\n%s\n", count, (x % 3 == 0) ? "YES" : "NO");
	}
	return (0);
}
