/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function(fn, t) {
    return async function(...args) {
        // Create a promise that rejects after t milliseconds
        const timeoutPromise = new Promise((_, reject) => {
            setTimeout(() => {
                reject("Time Limit Exceeded");
            }, t);
        });

        // Race between the execution of fn and the timeout
        try {
            const result = await Promise.race([fn(...args), timeoutPromise]);
            return result; // Resolve with the result of fn
        } catch (err) {
            throw err; // Reject with the timeout error or fn's error
        }
    };
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */