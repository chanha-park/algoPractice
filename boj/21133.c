#include <stdio.h>

int
main(void) {
    int n, i;
    scanf("%d", &n);

    switch (n % 6) {
        case 2: {
            for (i = 2; i <= n; i += 2) {
                printf("%d\n", i);
            }
            printf("3\n1\n");
            for (i = 7; i <= n; i += 2) {
                printf("%d\n", i);
            }
            printf("5\n");
            break;
        }
        case 3: {
            for (i = 4; i <= n; i += 2) {
                printf("%d\n", i);
            }
            printf("2\n");
            for (i = 5; i <= n; i += 2) {
                printf("%d\n", i);
            }
            printf("1\n3\n");
            break;
        }
        default: {
            for (i = 2; i <= n; i += 2) {
                printf("%d\n", i);
            }
            for (i = 1; i <= n; i += 2) {
                printf("%d\n", i);
            }
            break;
        }
    }
    return 0;
}
