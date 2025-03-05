/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    let map = new Map();
    
    // Helper function to merge objects
    function mergeObjects(obj1, obj2) {
        return { ...obj1, ...obj2 };
    }
    
    // Add arr1 elements to the map
    for (let obj of arr1) {
        map.set(obj.id, obj);
    }
    
    // Merge arr2 elements into the map
    for (let obj of arr2) {
        if (map.has(obj.id)) {
            map.set(obj.id, mergeObjects(map.get(obj.id), obj));
        } else {
            map.set(obj.id, obj);
        }
    }
    
    // Convert map values to an array and sort by id
    return Array.from(map.values()).sort((a, b) => a.id - b.id);
};