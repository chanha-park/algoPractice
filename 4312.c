#include <stdio.h>

void print_m(char *m, int m_len)
{
	for (int i = m_len - 1; i >=0; i--)
		printf("%c", m[i]);
}

int	three(char *m, int m_len)
{
	int	carr = 0;
	int	tmp;

	for (int i = 0; i < m_len; i++)
	{
		tmp = (m[i] - '0') * 3 + carr;
		carr = tmp / 10;
		m[i] = tmp % 10 + '0';
	}
	if (carr)
		m[m_len++] = carr + '0';
	return (m_len);
}

void	print_(unsigned long long n)
{
	char	m[30];
	int	m_len = 1;

	m[0] = '1';
	printf("{ ");
	while (n > 0)
	{
		if (n & 1)
		{
			print_m(m, m_len);
			if (n > 2)
				printf(", ");
			else
				printf(" ");
		}
		m_len = three(m, m_len);
		n >>= 1;
	}
	printf("}\n");
}

int	main(void)
{
	long long	n;

	while (1)
	{
		scanf("%llu", &n);
		if (n == 0)
			break ;
		print_(n - 1);
	}
}
