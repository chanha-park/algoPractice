#include <stdio.h>

/* // use recursion                */
/* int y(int n, int m);            */

/* int x(int n, int m) {           */
/*   if (n == 1)                   */
/*     return (0);                 */
/*   if (m == 1)                   */
/*     return (n - 1);             */
/*   return (n - 1 - y(m - 1, n)); */
/* }                               */

/* int y(int n, int m) {           */
/*   if (n == 1)                   */
/*     return (m - 1);             */
/*   if (m == 1)                   */
/*     return (0);                 */
/*   return (1 + x(m - 1, n));     */
/* }                               */

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  if (n < m)
    printf("%d %d\n",
           n / 2 - 1 + (n % 2),
           n / 2 + (n % 2) * (m - 2 * (n / 2) - 1));
  else
    printf("%d %d\n", m / 2 - 1 + (m % 2) * (n - 2 * (m / 2)), m / 2);
  return (0);
}
