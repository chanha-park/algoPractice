#include <stdio.h>

int	main(void)
{
	char	arr[16];

	for (int i = 0; i < 8; i++)
		scanf(" %c", &arr[2 * i]);
	for (int i = 0; i < 8; i++)
		scanf(" %c", &arr[2 * i + 1]);
	int	len = 16;
	while (len > 2)
	{
		for (int i = 0; i + 1 < len; i++)
			arr[i] = ((arr[i] - '0') + (arr[i + 1] - '0')) % 10 + '0';
		len--;
	}
	printf("%c%c\n", arr[0], arr[1]);
	return (0);
}
