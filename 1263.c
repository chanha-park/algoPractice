#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int	duration;
	int	due;
}	work;

int	cmp(const void *a, const void *b)
{
	work	x = *(work *)a;
	work	y = *(work *)b;

	if (x.due > y.due)
		return (1);
	if (x.due < y.due)
		return (-1);
	if (x.duration > y.duration)
		return (1);
	if (x.duration < y.duration)
		return (-1);
	return (0);
}

int	main(void)
{
	int	n;
	work	*works;

	scanf("%d", &n);
	works = malloc(sizeof(work) * n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &(works[i].duration), &(works[i].due));
	qsort(works, n, sizeof(work), cmp);
	int	start = 0;
	int	time_left = 2147483647, tmp;
	for (int i = 0; i < n; i++)
	{
		tmp = works[i].due - works[i].duration - start;
		if (tmp < 0)
		{
			printf("-1\n");
			return (0);
		}
		else
		{
			if (tmp < time_left)
				time_left = tmp;
			start += works[i].duration;
		}
	}
	printf("%d\n", time_left);
	return (0);
}
