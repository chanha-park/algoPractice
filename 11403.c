#include <stdio.h>
#include <stdlib.h>

int	dfs(int **mat, int *visit, int n, int i, int j, int len)
{
	if (len != 0 && i == j)
		return (1);
	for (int index = 0; index < n; index++)
	{
		if (mat[i][index] == 1 && visit[index] == 0)
		{
			visit[index] = 1;
			if (dfs(mat, visit, n, index, j, len + 1))
				return (1);
		}
	}
	return (0);
}

int	check(int **mat, int n, int i, int j)
{
	int	*visit = calloc(n, sizeof(int));
	int	flag;
	int	len = 0;

	flag = dfs(mat, visit, n, i, j, len);
	free(visit);
	return (flag);
}

int	main(void)
{
	int	n;
	int	**mat;

	scanf("%d", &n);
	mat = malloc(sizeof(int *) * n);
	for (int i = 0; i < n; i++)
	{
		mat[i] = malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++)
			scanf("%d", &mat[i][j]);
	}
	/* printf("=====\n"); */
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", check(mat, n, i, j));
		printf("\n");
	}
	return (0);
}
