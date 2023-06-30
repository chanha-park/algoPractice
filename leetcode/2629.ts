type F = (x: number) => number;

const compose = (functions: F[]): F => functions.reduce((a, b) => (x) => a(b(x)), <T>(x: T) => x);

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
