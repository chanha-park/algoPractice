#include <stdio.h>
#include <string.h>

void	check_palindrome(char *str)
{
	size_t	left = 0;
	size_t	right = strlen(str) - 1;

	while (left < right)
	{
		if (str[left] != str[right])
		{
			printf("no\n");
			return ;
		}
		left++;
		right--;
	}
	printf("yes\n");
}

int	main(void)
{
	char	str[6];

	while (1)
	{
		scanf("%s", str);
		if (strcmp(str, "0") == 0)
			break ;
		check_palindrome(str);
	}
	return (0);
}
