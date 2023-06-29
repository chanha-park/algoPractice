type ToBeOrNotToBe = {
    toBe: (val: any) => boolean;
    notToBe: (val: any) => boolean;
};

const expect = (val: any): ToBeOrNotToBe => {
    return {
        toBe: (v) => {
            if (v !== val) throw (new Error("Not Equal"))
            return true;
        },
        notToBe: (v) => {
            if (v === val) throw (new Error("Equal"))
            return true;
        },

    }
}


// function expect(val: any): ToBeOrNotToBe {

//     return {
//         toBe: (v) => v === val,
//         notToBe: (v) => v !== val,
//     };

// };

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */
