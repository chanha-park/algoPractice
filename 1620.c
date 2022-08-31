#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int		nbr;
	char	name[21];
}	entry;

int	cmp(const void *a, const void *b)
{
	return (strcmp(((entry *)a)->name, ((entry *)b)->name));
}

int	main(void)
{
	int	n, m;
	entry	temp;
	entry	*dict;
	entry	*copy;

	scanf("%d %d", &n, &m);
	dict = malloc(sizeof(entry) * n);
	copy = malloc(sizeof(entry) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", dict[i].name);
		memcpy(copy[i].name, dict[i].name, 21);
		dict[i].nbr = i;
		copy[i].nbr = i;
	}
	qsort(copy, n, sizeof(entry), cmp);
	for (int i = 0; i < m; i++)
	{
		scanf("%s", temp.name);
		if (temp.name[0] >= '0' && temp.name[0] <= '9')
			printf("%s\n", dict[atoi(temp.name) - 1].name);
		else
		{
			printf("%d\n", ((entry *)bsearch(&temp, copy, n, sizeof(entry), cmp))->nbr + 1);
		}
	}
	return (0);
}
