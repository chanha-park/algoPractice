#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char	key[21];
	char	data[21];
}	node;

int	cmp(const void *a, const void *b)
{
	char	*s1 = ((node *)a)->key;
	char	*s2 = ((node *)b)->key;

	return (strcmp(s1, s2));
}

void	search(node *arr, int n, char *s)
{
	int	left, right, mid;

	left = 0;
	right = n;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (strcmp(s, arr[mid].key) == 0)
		{
			printf("%s\n", arr[mid].data);
			return ;
		}
		if (strcmp(s, arr[mid].key) > 0)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
}

int	main(void)
{
	int	n, m;
	node	*arr;
	char	s[21];

	scanf("%d %d", &n, &m);
	arr = malloc(sizeof(node) * n);
	for (int i = 0; i < n; i++)
		scanf("%s %s", arr[i].key, arr[i].data);
	qsort(arr, n, sizeof(node), cmp);
	while (m--)
	{
		scanf("%s", s);
		search(arr, n, s);
	}
	/* for (int i = 0; i < n; i++)                     */
	/*     printf("%s %s\n", arr[i].key, arr[i].data); */
	return (0);
}
