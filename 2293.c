#include <stdio.h>
#include <stdlib.h>

int	count = 0;

void	f(int n, int *arr, int idx)
{
	if (n == 0)
	{
		count++;
		return ;
	}
	for (int i = n; i >= 0; i -= )
}

int	main(void)
{
	int	n, k;
	int	*arr;

	scanf("%d %d", &n, &k);
	arr = malloc(sizeof(int) * (n + 1));
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	arr[k] = 0;
	f(n, arr, 0);
	printf("%d\n", count);
}
