function createHelloWorld() {
    return function(..._args: any[]): string {
        return "Hello World"
    };
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */
