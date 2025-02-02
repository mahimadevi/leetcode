class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // Initialize two variables to store the smallest and second smallest elements
        int first = INT_MAX;  // Smallest element so far
        int second = INT_MAX; // Second smallest element so far

        // Traverse the array
        for (int num : nums) {
            // If the current number is smaller than or equal to `first`, update `first`
            if (num <= first) {
                first = num;
            }
            // If the current number is greater than `first` but smaller than or equal to `second`, update `second`
            else if (num <= second) {
                second = num;
            }
            // If the current number is greater than both `first` and `second`, we found a valid triplet
            else {
                return true;
            }
        }

        // If no triplet is found after traversing the array, return false
        return false;
    }
};