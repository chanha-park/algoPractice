#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	n, m, i, j;
	int	*sum;

	scanf("%d %d", &n, &m);
	sum = malloc(sizeof(int) * (n + 1));
	sum[0] = 0;
	for (int k = 0; k < n; k++)
	{
		scanf("%d", &sum[k + 1]);
		sum[k + 1] += sum[k];
	}
	while (m--)
	{
		scanf("%d %d", &i, &j);
		printf("%d\n", sum[j] - sum[i - 1]);
	}
	return (0);
}
