/**
 * @param {number} n
 * @return {Function} counter
 */
const createCounter = (n: number): Function => () => n++

const counter = createCounter(10)
console.log(counter()) // 10
console.log(counter()) // 11
console.log(counter()) // 12

