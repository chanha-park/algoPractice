#include <stdio.h>

int f(int n)
{
	int	ret = 1;
	int	a = 10 % n;
	int	sum = 1;

	while (1)
	{
		if (sum % n == 0) break ;
		sum *= a; sum += 1; sum %= n; ret++;
	}
	return (ret);
}

int main(void)
{
	int	n;

	scanf("%d", &n);
	if (n % 2 == 0 || n % 5 == 0)
		printf("-1\n");
	else
		printf("%d\n", f(n));
	return (0);
}
