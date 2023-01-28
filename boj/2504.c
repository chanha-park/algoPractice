#include <stdio.h>

int	main(void)
{
	char	str[31];
	char	symbol[16];
	int		symbol_idx = 0;
	int		tmp = 1;
	int		flag = 0;
	int		ans = 0;

	scanf("%s", str);
	for (int idx = 0; str[idx]; idx++)
	{
		if (str[idx] == '(')
		{
			symbol[symbol_idx++] = '(';
			tmp *= 2;
			flag = 1;
		}
		else if (str[idx] == '[')
		{
			symbol[symbol_idx++] = '[';
			tmp *= 3;
			flag = 1;
		}
		else if (str[idx] == ')')
		{
			if (symbol[--symbol_idx] != '(')
			{
				printf("0\n");
				return (0);
		}
			if (flag)
				ans += tmp;
			flag = 0;
			tmp /= 2;
		}
		else if (str[idx] == ']')
		{
			if (symbol[--symbol_idx] != '[')
			{
				printf("0\n");
				return (0);
			}
			if (flag)
				ans += tmp;
			flag = 0;
			tmp /= 3;
		}
		else
		{
			printf("0\n");
			return (0);
		}
	}
	if (symbol_idx != 0)
		printf("0\n");
	else
		printf("%d\n", ans);
}
