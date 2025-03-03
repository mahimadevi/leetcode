var TimeLimitedCache = function() {
    this.cache = new Map(); // Use a Map to store key-value pairs with expiration times
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    let found = this.cache.has(key); // Check if the key already exists

    // If the key exists, clear its previous timeout to avoid premature deletion
    if (found) {
        clearTimeout(this.cache.get(key).ref); // Cancel the previous timeout
    }

    // Set a new timeout to delete the key after the duration expires
    const ref = setTimeout(() => this.cache.delete(key), duration);

    // Store the value and the timeout reference in the cache
    this.cache.set(key, {
        value, // Equivalent to `value: value`
        ref,   // Reference to the timeout for cleanup
    });

    return found; // Return whether the key already existed
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    // If the key exists, return its value; otherwise, return -1
    return this.cache.has(key) ? this.cache.get(key).value : -1;
    
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
     // The size of the Map represents the count of non-expired keys
    return this.cache.size;
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */