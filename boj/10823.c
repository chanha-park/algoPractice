#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	char	buff[10000];
	int	ret;
	int	idx;
	int	sum = 0;
	int	curr = 0;

	while (1)
	{
		ret = read(0, buff, 10000);
		if (ret <= 0)
			break ;
		idx = 0;
		while (idx < ret)
		{
			switch (buff[idx])
			{
				case ('\n'):
					break ;
				case (','):
					sum += curr;
					curr = 0;
					break ;
				default:
					curr = curr * 10 + buff[idx] - '0';
			}
			idx++;
		}
	}
	sum += curr;
	printf("%d\n", sum);
}
