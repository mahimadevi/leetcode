/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
     // Cache to store computed results
    const cache = new Map();


    // Return a new function that wraps around the original function
    return function(...args) {
        // Convert arguments to a key (string representation)
        const key = JSON.stringify(args);

        // If the result exists in cache, return it
        if (cache.has(key)) {
            return cache.get(key);
        }

        // Otherwise, call the original function and store the result
        const result = fn(...args);
        cache.set(key, result);


        return result;
}
}

/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */