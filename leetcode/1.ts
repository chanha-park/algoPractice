function twoSum(nums: number[], target: number): number[] {
    const copy = nums.map((v, idx) => {
        return {
            value: v,
            index: idx,
        }
    }).sort((a, b) => a.value - b.value);

    // console.log(copy);

    let left = 0;
    let right = copy.length - 1;

    while (left < right) {
        if (copy[left].value + copy[right].value < target)
            ++left;
        else if (copy[left].value + copy[right].value > target)
            --right;
        else
            return [copy[left].index, copy[right].index];
    }
    return [];
}
