/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        const results = []; // Array to store resolved values
        let completed = 0; // Counter to track completed promises

        // If the input array is empty, resolve immediately with an empty array
        if (functions.length === 0) {
            resolve(results);
            return;
        }

        // Loop through each function and execute it
        functions.forEach((fn, index) => {
            fn() // Execute the function to get the promise
                .then((value) => {
                    results[index] = value; // Store the resolved value at the correct index
                    completed++; // Increment the completion counter

                    // If all promises have resolved, resolve the new promise
                    if (completed === functions.length) {
                        resolve(results);
                    }
                })
                .catch((error) => {
                    // If any promise is rejected, reject the new promise with the error
                    reject(error);
                });
        });
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */