function chunk(arr: any[], size: number): any[][] {

    let bucket: any[] = [];
    let result: any[][] = [];

    arr.forEach((value, index) => {
        bucket.push(value);
        if (index % size === size - 1) {
            result.push(bucket);
            bucket = [];
        }
    });

    if (bucket.length > 0) result.push(bucket);

    return result;
};

const a = [8, 5, 3, 2, 6];
const b = 3;

console.log(chunk(a, b));
