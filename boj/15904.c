#include <unistd.h>

int
main(void) {
  char s[1001];
  char const a[] = {'U', 'C', 'P', 'C'};
  ssize_t const r = read(0, s, 1001);
  ssize_t i, j;
  for (i = 0, j = 0; i < r; ++i) {
    if (s[i] == a[j]) {
      ++j;
      if (j == 4)
        break;
    }
  }
  write(1, j == 4 ? "I love UCPC\n" : "I hate UCPC\n", 12);
  return 0;
}
