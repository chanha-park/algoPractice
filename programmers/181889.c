#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void
intcopy(int* dst, int* src, int n) {
  if (n <= 0)
    return;
  *dst = *src;
  intcopy(dst + 1, src + 1, n - 1);
}

// num_list_len은 배열 num_list의 길이입니다.
int*
solution(int num_list[], size_t num_list_len, int n) {
  // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게
  // 변경해주세요.
  int* answer = (int*)malloc(sizeof(int) * n);
  intcopy(answer, num_list, n);
  return answer;
}
