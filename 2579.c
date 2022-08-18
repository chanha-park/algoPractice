#include <stdio.h>
#include <stdlib.h>

int	find_min(int *score, int *sol, int size, int start)
{
	int	m1, m2;
	int	curr;

	if (start >= size)
		return (0);
	if (start < 0)
		curr = 0;
	else
		curr = score[start];
	if (sol[start + 1] < 0)
	{
		m1 = find_min(score, sol, size, start + 2);
		m2 = find_min(score, sol, size, start + 3);
		if (m1 < m2)
			sol[start + 1] = curr + m1;
		else
			sol[start + 1] = curr + m2;
	}
	return (sol[start + 1]);
}

int	main(void)
{
	int	n;
	int	*score;
	int	*sol;
	int	total_score = 0;
	int	min;

	scanf("%d", &n);
	score = malloc(sizeof(int) * n);
	sol = malloc(sizeof(int) * (n + 1));
	sol[0] = -1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &score[i]);
		total_score += score[i];
		sol[i + 1] = -1;
	}
	sol[n] = 2147483647;
	for (int i = n - 1; i >= -1; i--)
	{
		find_min(score, sol, n, i);
	}
	min = sol[0];
	if (n > 1 && min > sol[1])
		min = sol[1];
	printf("%d\n", total_score - min);
	return (0);
}
