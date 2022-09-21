#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int	life;
	int	joy;
}	person;

int	cmp(const void *a, const void *b)
{
	person	x = *(person *)a;
	person	y = *(person *)b;

	if (x.joy > y.joy)
		return (-1);
	else if (x.joy < y.joy)
		return (1);
	else
	{
		if (x.life > y.life)
			return (1);
		else if (x.life < y.life)
			return (-1);
		return (0);
	}
}

int	max_joy(person *people, int n, int start, int life)
{
	if (start < n && life > 0)
	{
		if (life > people[start].life)
		{
			int	a = people[start].joy + max_joy(people, n, start + 1, life - people[start].life);
			int	b = max_joy(people, n, start + 1, life);
			return (a > b ? a : b);
		}
		else
			return (max_joy(people, n, start + 1, life));
	}
	else
	{
		return (0);
	}
}

int	main(void)
{
	int	n;
	person	people[20];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &(people[i].life));
	for (int i = 0; i < n; i++)
		scanf("%d", &(people[i].joy));

	printf("%d\n", max_joy(people, n, 0, 100));

	return (0);
}
