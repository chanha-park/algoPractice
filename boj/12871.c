#include <stdio.h>
#include <string.h>

int
gcd(int a, int b) {
    int c;

    while ((c = a % b)) {
        a = b;
        b = c;
    }
    return b;
}

int
solve(char* s, char* t) {
    int const len1 = strlen(s);
    int const len2 = strlen(t);
    int const len = len1 * len2 / gcd(len1, len2);

    for (int i = 0; i < len; ++i) {
        if (s[i % len1] != t[i % len2]) {
            return 0;
        }
    }
    return 1;
}

int
main(void) {
    char s[51];
    char t[51];

    scanf("%s", s);
    scanf("%s", t);
    printf(solve(s, t) ? "1" : "0");
    return 0;
}
