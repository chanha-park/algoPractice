#include <stdio.h>

int	main(void)
{
	char	str[9];
	int	n = 0;

	for (int i = 0; i < 8; i++)
	{
		scanf("%s", str);
		for (int j = 0; j < 8; j++)
		{
			if (str[j] == 'F' && (i + j + 1) % 2)
				n++;
		}
	}
	printf("%d\n", n);
	return (0);
}
