/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
     const result = [];
    for (let i = 0; i < arr.length; i += size) {
        // Slice the array from the current index to the current index + size
        const chunk = arr.slice(i, i + size);
        result.push(chunk);
    }
    return result;
};
