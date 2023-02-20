int searchInsert(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize;
    int mid;

    while (left < right) {
        mid = (left + right) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;
        } else {
            return (mid);
        }
    }
    return (left);
}
