function map(arr: number[], fn: (n: number, i: number) => number): number[] {
    const returnedArray: number[] = [];
    for (let i = 0; i < arr.length; ++i) {
        returnedArray[i] = fn(arr[i], i);
    }
    return returnedArray;
};
