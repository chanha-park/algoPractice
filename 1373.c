#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s[1000001];
	char	buff[1000001];
	char	*ptr;
	size_t	len, idx;
	int	a;

	scanf("%s", s);
	ptr = s;
	len = strlen(ptr);
	idx = 0;
	a = 0;
	while (len > 0)
	{
		a = (a << 1) + (*ptr - '0');
		ptr++;
		len--;
		if (len % 3 == 0)
		{
			buff[idx++] = a + '0';
			a = 0;
		}
	}
	buff[idx] = '\0';
	printf("%s\n", buff);
	return (0);
}
