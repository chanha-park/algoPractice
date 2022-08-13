#include <stdio.h>
#include <string.h>

int	cnt_end(char *str)
{
	int	count = 0;

	count += (str[0] == str[1]) && (str[1] == str[2]);
	count += (str[3] == str[4]) && (str[4] == str[5]);
	count += (str[6] == str[7]) && (str[7] == str[8]);

	count += (str[0] == str[3]) && (str[3] == str[6]);
	count += (str[1] == str[4]) && (str[4] == str[7]);
	count += (str[2] == str[5]) && (str[5] == str[8]);

	count += (str[0] == str[4]) && (str[4] == str[8]);
	count += (str[2] == str[4]) && (str[4] == str[2]);
	return (count);
}

int	is_valid(char *str)
{
	int	idx = 0;
	int	cnt_x = 0;
	int	cnt_o = 0;
	int	end_cnt;

	while (idx < 9)
	{
		if (str[idx] == 'X')
			cnt_x++;
		if (str[idx] == 'O')
			cnt_o++;
		idx++;
	}
	if (cnt_x < cnt_y)
		return (0);
	end_cnt = cnt_end(str);
	if (end_cnt == 1)
		return (1);
	if (end_cnt == 0 && cnt_x + cnt_o != 9)
		return (0);
}

int	main(void)
{
	char	str[10];

	while (1)
	{
		memset(str, 0, 10);
		scanf("%s", str);
		if (str[0] == 'e')
			break ;
		if (is_valid(str))
			printf("valid\n");
		else
			printf("invalid\n");
	}
	return (0);
}
