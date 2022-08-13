#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	n, k;
	int	*arr;

	scanf("%d %d", &n, &k);
	arr = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d,", &arr[i]);
	while (k)
	{
		for (int i = 0; i + 1 < n; i++)
			arr[i] = arr[i + 1] - arr[i];
		n--;
		k--;
	}
	for (int i = 0; i + 1 < n; i++)
		printf("%d,", arr[i]);
	printf("%d\n", arr[n - 1]);
	return (0);
}
