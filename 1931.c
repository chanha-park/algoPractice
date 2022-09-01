#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int	start;
	int	end;
}	time;

int	cmp(const void *a, const void *b)
{
	int	x = ((time *)a)->end;
	int	y = ((time *)b)->end;

	if (x > y)
		return (1);
	else if (x < y)
		return (-1);
	else
	{
		x = ((time *)a)->start;
		y = ((time *)b)->start;
		if (x > y)
			return (1);
		else if (x < y)
			return (-1);
		else
			return (0);
	}
}

int	max_meetings(time *meetings, int size)
{
	int	end = 0;
	int	count = 0;

	for (int i = 0; i < size; i++)
	{
		if (meetings[i].start >= end)
		{
			count++;
			end = meetings[i].end;
		}
	}
	return (count);
}

int	main(void)
{
	int		n;
	time	*meetings;

	scanf("%d", &n);
	meetings = malloc(sizeof(time) * n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &meetings[i].start, &meetings[i].end);
	qsort(meetings, n, sizeof(time), cmp);
	printf("%d\n", max_meetings(meetings, n));
	return (0);
}
