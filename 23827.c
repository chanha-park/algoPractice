#include <stdio.h>

int	main(void)
{
	int	n, x;
	long long	sum = 0;
	long long	ans = 0;

	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &x);
		ans += sum * x;
		ans %= 1000000007;
		sum += x;
		sum %= 1000000007;
	}
	printf("%lld\n", ans);
	return (0);
}
