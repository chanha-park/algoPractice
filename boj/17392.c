#include <stdio.h>

long long	get_gloomy(int n, int x)
{
	long long	gloom = 0;
	long long	a;

	while (x > 0)
	{
		a = x / (n + 1);
		x -= a;
		gloom += (a * (a + 1) * (2 * a + 1)) / 6;
		n--;
	}
	return (gloom);
}

int	main(void)
{
	int	n, m, tmp;
	int	non_gloomy_days;

	scanf("%d %d", &n, &m);
	non_gloomy_days = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		non_gloomy_days += tmp + 1;
	}
	if (non_gloomy_days >= m)
		printf("%c\n", '0');
	else
		printf("%lld\n", get_gloomy(n, m - non_gloomy_days));
	return (0);
}
