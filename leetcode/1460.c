bool canBeEqual(int* target, int targetSize, int* arr, int arrSize){
    int count[1001];
    for (int i = 0; i < 1001; ++i) {
        count[i] = 0;
    }
    for (int i = 0; i < targetSize; ++i) {
        count[target[i]] += 1;
        count[arr[i]] -= 1;
    }
    for (int i = 0; i < 1001; ++i) {
        if (count[i] != 0)
            return (false);
    }
    return (true);
}
