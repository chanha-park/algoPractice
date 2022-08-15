#include <stdio.h>
#include <string.h>

int	arr[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

int	main(void)
{
	int		a[4001];
	char	c;
	int		len;

	c = '\0';
	len = 0;
	while (scanf("%c", &c) && c != '\n')
		a[2 * len++] = arr[c - 'A'];
	len = 0;
	while (scanf("%c", &c) && c != '\n')
		a[1 + 2 * len++] = arr[c - 'A'];
	len *= 2;
	while (len > 2)
	{
		for (int i = 0; i + 1 < len; i++)
			a[i] = (a[i] + a[i + 1]) % 10;
		len--;
	}
	printf("%2d\n", 10 * a[0] + a[1]);
	return (0);
}
