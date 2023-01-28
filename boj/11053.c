#include <stdio.h>
#include <stdlib.h>

// LIS, longest increasing subsequence

int main(void) {
  int n, len, newLen, left, right, mid;

  scanf("%d", &n);
  int* arr = malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  /* int* p = malloc(sizeof(int) * n); */
  int* m = malloc(sizeof(int) * (n + 1));

  len = 0;
  m[0] = -1;

  for (int i = 0; i < n; i++) {
    left = 1;
    right = len + 1;
    while (left < right) {
      mid = (left + right) / 2;
      if (arr[m[mid]] >= arr[i])
        right = mid;
      else
        left = mid + 1;
    }
    newLen = left;
    // p[i] = m[newLen - 1];
    m[newLen] = i;

    if (newLen > len)
      len = newLen;
  }

  /* int* s = malloc(sizeof(int) * len); */
  /* int k = m[len];                     */

  printf("%d\n", len);

  /* for (int i = len - 1; i >= 0; i--) { */
  /*   s[i] = arr[k];                     */
  /*   k = p[k];                          */
  /* }                                    */

  /* for (int i = 0; i < len; i++)        */
  /*   std::cout << s[i] << " ";          */
  /* std::cout << "\n";                   */
  return (0);
}
