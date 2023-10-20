#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int
solution(int num_list[], size_t num_list_len, int n) {
  return num_list_len == 0  ? 0
         : num_list[0] == n ? 1
                            : solution(num_list + 1, num_list_len - 1, n);
}
