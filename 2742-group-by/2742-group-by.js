/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    const result = {};
    for (const item of this) {
        const key = fn(item); // Get the key using the provided function
        if (!result[key]) {
            result[key] = []; // Initialize the key if it doesn't exist
        }
        result[key].push(item); // Add the item to the corresponding key
    }
    return result;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */