
function isEmpty(obj: Record<string, any> | any[]): boolean {
    return Object.keys(obj).length === 0;
};


const obj1 = {
    "x": 5,
    "y": 42,
};

const obj2 = {}

const obj3 = [null, false, 0]

const obj4 = []

for (const k in obj1) {
    console.log(k);
}

// console.log(isEmpty(obj1));
// console.log(isEmpty(obj2));
// console.log(isEmpty(obj3));
// console.log(isEmpty(obj4));
