#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int	data;
	int	count;
}	node;

int	main(void)
{
	int	n, m, tmp;
	node	*arr = NULL;

	scanf("%d", &n);
	arr = malloc(sizeof(node) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &tmp);
	}
	return (0);
}
