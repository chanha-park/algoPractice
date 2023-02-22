int countDays(int* weights, int weightsSize, int cap) {
    int count = 1;
    int sum = 0;
    for (int i = 0; i < weightsSize; ++i) {
        if (weights[i] > cap) {
            return (50000);
        }
        else if (sum + weights[i] <= cap) {
            sum += weights[i];
        } else {
            ++count;
            sum = weights[i];
        }
    }
    return (count);
}

int shipWithinDays(int* weights, int weightsSize, int days){
    int left = 0;
    int right = -1;
    int mid;
    int ans;
    for (int i = 0; i < weightsSize; ++i) {
        if (weights[i] > right)
            right = weights[i];
    }
    right *= 1 + weightsSize / days;
    ans = right;
    while (left < right) {
        mid = (left + right) / 2;
        if (countDays(weights, weightsSize, mid) > days) {
            left = mid + 1;
        } else {
            ans = mid;
            right = mid;
        }
    }
    return (ans);
}

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int weightsSize;
    int *weights;
    int days;

    scanf("%d", &weightsSize);
    weights = malloc(sizeof(int) * weightsSize);
    for (int i = 0; i < weightsSize; ++i)
        scanf("%d", &weights[i]);
    scanf("%d", &days);
    printf("%d", shipWithinDays(weights, weightsSize, days));
    return (0);
}
