function* fibGenerator(): Generator<number, any, number> {
    for (let [a, b] = [0, 1]; true; [a, b] = [b, a + b]) {
        yield a;
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */

const gen = fibGenerator();

for (let i = 0; i < 11; ++i) {
    console.log(gen.next().value);
}
