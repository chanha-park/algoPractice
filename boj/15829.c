#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	int				n;
	char			s[50];
	const int		m = 1234567891;
	long			r = 1;
	long			hash = 0;

	scanf("%d", &n);
	read(0, s, n + 1);
	for (int i = 0; i < n; i++)
	{
		hash += r * (s[i] - 'a' + 1);
		r *= 31;
		hash %= m;
		r %= m;
	}
	printf("%ld\n", hash);
	return (0);
}
