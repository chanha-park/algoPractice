#include <stdio.h>
#include <string.h>

typedef unsigned long long  ull;

int	main(void)
{
	ull	a;
	ull	b;
	ull	x;
	ull	y;
	ull	i;
	ull	t1;
	ull	t2;
	ull	t;

	scanf("%lld %lld", &a, &b);
	i = 0;
	t1 = 0;
	t2 = 1;
	while (i < a + 1)
	{
		t = t2;
		t2 = (t2 + t1) % 1000000000;
		t1 = t;
		i++;
	}
	x = t1;
	/* i = 0;                           */
	/* t1 = 0;                          */
	/* t2 = 1;                          */
	/* while (i < b + 2)                */
	/* {                                */
	/*     t = t2;                      */
	/*     t2 = (t2 + t1) % 1000000000; */
	/*     t1 = t;                      */
	/*     i++;                         */
	/* }                                */
	y = t1;
	printf("%lld %lld\n", x, y);
	return (0);
}
