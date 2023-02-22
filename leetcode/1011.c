int countDays(int* weights, int weightsSize, int cap) {
    int count = 1;
    int sum = 0;
    for (int i = 0; i < weightsSize; ++i) {
        if (sum + weights[i] <= cap) {
            sum += weights[i];
        } else {
            ++count;
            sum = weights[i];
        }
    }
    return (count);
}

int shipWithinDays(int* weights, int weightsSize, int days){
    int left = -1;
    int right = 0;
    int mid;
    int ans;
    for (int i = 0; i < weightsSize; ++i) {
        if (weights[i] > left)
            left = weights[i];
        right += weights[i];
    }
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
