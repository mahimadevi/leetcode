/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
     let timeoutId; // Stores the ID of the current timeout

    return function(...args) {
        // Clear the previous timeout if it exists
        clearTimeout(timeoutId);

        // Set a new timeout to execute the function after t milliseconds
        timeoutId = setTimeout(() => {
            fn(...args); // Call the original function with the passed arguments
        }, t);
    };
};

/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */