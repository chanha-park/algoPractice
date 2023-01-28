#include <stdio.h>

int	main(void)
{
	int	n;
	int	w;
	int	max_weight;
	int	min_limit;

	scanf("%d", &n);
	scanf("%d", &w);
	max_weight = w;
	min_limit = w;
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &w);
		if (min_limit > w)
			min_limit = w;
		if (max_weight < (i + 1) * min_limit)
			max_weight = (i + 1) * min_limit;
	}
	printf("%d\n", max_weight);
	return (0);
}
