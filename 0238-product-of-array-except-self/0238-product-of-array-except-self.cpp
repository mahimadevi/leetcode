class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1); // Initialize result array with 1 (since we'll multiply)
        
        // Step 1: Calculate the left products and store in the result array
        int leftProduct = 1;  // Initialize the left product as 1 (nothing on the left of the first element)
        for (int i = 0; i < n; i++) {
            result[i] = leftProduct; // For each element, the left product is stored in result[i]
            leftProduct *= nums[i];  // Update leftProduct for the next element
        }

        // Step 2: Calculate the right products and update the result array
        int rightProduct = 1;  // Initialize the right product as 1 (nothing on the right of the last element)
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= rightProduct;  // Multiply the current value in result by the right product
            rightProduct *= nums[i];    // Update rightProduct for the next element
        }

        return result; // Return the final result array
    }
};
