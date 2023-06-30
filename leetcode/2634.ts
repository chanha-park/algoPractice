function filter(arr: number[], fn: (n: number, i: number) => any): number[] {
    const filteredArr: number[] = []

    arr.forEach((n, i) => {
        if (fn(n, i)) { filteredArr.push(n); }
    });
    return filteredArr;
};
