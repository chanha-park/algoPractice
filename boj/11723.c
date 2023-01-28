#include <stdio.h>

int	main(void)
{
	int	n, x, set;
	char	cmd[10];

	set = 0;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", cmd);
		if (cmd[0] == 'e')
			set = 0;
		else if (cmd[1] == 'l')
			set = (1 << 20) - 1;
		else
		{
			scanf("%d", &x);
			x = 1 << (x - 1);
			if (cmd[0] == 'a')
				set |= x;
			else if (cmd[0] == 'r')
				set &= ~x;
			else if (cmd[0] == 'c')
				printf("%d\n", (set & x) != 0);
			else if (cmd[0] == 't')
				set ^= x;
		}
	}
	return (0);
}
