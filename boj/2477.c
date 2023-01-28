#include <stdio.h>

typedef struct
{
	int	dir;
	int	len;
}	st;

int	main(void)
{
	int	k, dir, len, idx;
	int	conv[4] = {0, 2, 3, 1};
	st	arr[6];

	idx = -1;
	scanf("%d\n", &k);
	for (int i = 0; i < 6; i++)
	{
		scanf("%d %d", &dir, &len);
		arr[i].dir = conv[dir - 1];
		arr[i].len = len;
		if (i)
		{
			if ((arr[i - 1].dir + 1) % 4 != arr[i].dir)
				idx = i;
		}
	}
	if (idx < 0)
		idx = 0;
	printf("%d\n", k * (arr[(idx + 2) % 6].len * arr[(idx + 3) % 6].len - arr[idx].len * arr[(idx + 5) % 6].len));
	return (0);
}
