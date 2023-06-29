type Fn = (...args: any[]) => any

function once(fn: Fn): Fn {
    let isCalled = false;
    const foo = (...args: any[]) => {
        if (!isCalled) {
            isCalled = true;
            return fn(...args);
        }
    };
    return foo;
}
let fn = (a, b, c) => (a + b + c)
let onceFn = once(fn)

console.log(onceFn(1, 2, 3)); // 6
console.log(onceFn(2, 3, 6)); // returns undefined without calling fn

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
