type ReturnObj = {
    increment: () => number,
    decrement: () => number,
    reset: () => number,
}

const createCounter = (init: number): ReturnObj => {
    const resetValue = init;
    return {
        decrement: () => --init,
        increment: () => ++init,
        reset: () => {
            init = resetValue;
            return init;
        },
    };
}


const counter = createCounter(5)
console.log(counter.increment());
console.log(counter.reset());
console.log(counter.decrement());


/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
