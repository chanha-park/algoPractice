class ArrayWrapper {
    contents: number[];

    constructor(nums: number[]) {
        this.contents = [...nums];
    }

    valueOf() {
        return this.contents.reduce((x, y) => x + y, 0);
    }

    toString() {
        return `[${this.contents}]`;
    }
};

/**
 * const obj1 = new ArrayWrapper([1,2]);
 * const obj2 = new ArrayWrapper([3,4]);
 * obj1 + obj2; // 10
 * String(obj1); // "[1,2]"
 * String(obj2); // "[3,4]"
 */
