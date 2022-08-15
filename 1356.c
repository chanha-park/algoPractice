#include <stdio.h>
#include <string.h>

int	prod_(char *s, int l, int r)
{
	int	p = 1;

	while (l <= r)
		p *= s[l++] - '0';
	return (p);
}

int	is_(char *s)
{
	int	idx = 0;
	int	len = strlen(s);

	while (idx + 1 < len)
	{
		if (prod_(s, 0, idx) == prod_(s, idx + 1, len - 1))
			return (1);
		idx++;
	}
	return (0);
}

int	main(void)
{
	char	s[20];

	scanf("%s", s);
	if (is_(s))
		printf("YES\n");
	else
		printf("NO\n");
	return (0);
}
