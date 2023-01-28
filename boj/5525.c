#include <stdio.h>
#include <stdlib.h>

int	get_ioi_len(char *s)
{
	int	len = 0;
	char	c = 'I';

	while (*s == c)
	{
		c ^= 6;
		s++;
		if (*s == 'I' && c == 'I')
			len++;
	}
	return (len);
}

int	main(void)
{
	int	n, m;
	char	*s;
	int	len;
	int	count = 0;

	scanf("%d", &n);
	scanf("%d", &m);
	s = malloc(sizeof(char) * (m + 1));
	scanf("%s", s);
	for (int i = 0; s[i];)
	{
		len = get_ioi_len(s + i);
		if (len >= n)
			count += (len - n + 1);
		i += 2 * len + 1;
		while (s[i] == 'O')
			i++;
	}
	printf("%d\n", count);
	return (0);
}
