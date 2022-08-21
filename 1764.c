#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// {{{ sol 1

/* char	**c;                                                */
/* int		count = 0;                                          */

/* int	cmp(const void *s1, const void *s2)                  */
/* {                                                        */
/*     return (strcmp((const char *)s1, (const char *)s2)); */
/* }                                                        */

/* void	search(char (*a)[21], int n, char (*b)[21], int m)  */
/* {                                                        */
/*     int	left, right, mid;                                */
/*     char	*tofind;                                        */

/*     left = 0;                                            */
/*     for (int i = 0; i < m; i++)                          */
/*     {                                                    */
/*         tofind = b[i];                                   */
/*         right = n;                                       */
/*         while (left < right)                             */
/*         {                                                */
/*             mid = (left + right) / 2;                    */
/*             if (strcmp(tofind, a[mid]) < 0)              */
/*             {                                            */
/*                 right = mid;                             */
/*             }                                            */
/*             else                                         */
/*             {                                            */
/*                 left = mid + 1;                          */
/*                 if (strcmp(tofind, a[mid]) == 0)         */
/*                 {                                        */
/*                     c[count++] = tofind;                 */
/*                     break ;                              */
/*                 }                                        */
/*             }                                            */
/*         }                                                */
/*     }                                                    */
/* }                                                        */

/* int	main(void)                                           */
/* {                                                        */
/*     int	n, m;                                            */
/*     char	(*a)[21];                                       */
/*     char	(*b)[21];                                       */

/*     scanf("%d %d", &n, &m);                              */
/*     a = malloc(sizeof(char [21]) * (n + 1));             */
/*     b = malloc(sizeof(char [21]) * (m + 1));             */
/*     for (int i = 0; i < n; i++)                          */
/*         scanf("%s", a[i]);                               */
/*     for (int i = 0; i < m; i++)                          */
/*         scanf("%s", b[i]);                               */
/*     qsort(a, n, sizeof(char [21]), cmp);                 */
/*     qsort(b, m, sizeof(char [21]), cmp);                 */

/*     if (n > m)                                           */
/*     {                                                    */
/*         c = malloc(sizeof(char *) * (m + 1));            */
/*         search(a, n, b, m);                              */
/*     }                                                    */
/*     else                                                 */
/*     {                                                    */
/*         c = malloc(sizeof(char *) * (n + 1));            */
/*         search(b, m, a, n);                              */
/*     }                                                    */
/*     printf("%d\n", count);                               */
/*     for (int i = 0; i < count; i++)                      */
/*     {                                                    */
/*         printf("%s\n", c[i]);                            */
/*     }                                                    */
/*     free(a);                                             */
/*     free(b);                                             */
/*     free(c);                                             */
/*     return (0);                                          */
/* }                                                        */

// }}}

// {{{ sol 2

char	**c;
int		count = 0;

int	cmp(const void *s1, const void *s2)
{
	int	ret = strcmp((const char *)s1, (const char *)s2);
	
	if (ret == 0)
	{
		c[count++] = strdup(s1);
	}
	return (ret);
}

int	main(void)
{
	int	n, m;
	char	(*a)[21];

	scanf("%d %d", &n, &m);
	a = malloc(sizeof(char [21]) * (n + m));

	for (int i = 0; i < n + m; i++)
		scanf("%s", a[i]);

	if (n > m)
	{
		c = malloc(sizeof(char *) * (m + 1));
	}
	else
	{
		c = malloc(sizeof(char *) * (n + 1));
	}

	qsort(a, n + m, sizeof(char [21]), cmp);

	printf("%d\n", count);
	for (int i = 0; i < count; i++)
	{
		printf("%s\n", c[i]);
	}
	free(a);
	return (0);
}

// }}}
