int singleNonDuplicate(int* nums, int numsSize) {
    int ret = 0;
    while (numsSize-- > 0) {
        ret ^= nums[numsSize];
    }
    return (ret);
}
