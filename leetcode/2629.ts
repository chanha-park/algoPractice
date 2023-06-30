type F = (x: number) => number;

const compose = (functions: F[]): F => {
    const id = (x) => x;
    return functions.reduce((a, b) => (x) => a(b(x)), id);
};

// function foo<T>(x :T){console.log(x)}

// Array<F>.reduce(callbackfn: (previousValue: F, currentValue: F, currentIndex: number, array: F[]) => F, initialValue: F): F

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
