class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // Step 1: Calculate the sum of the first 'k' elements
        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }
        
        // Step 2: Initialize maxSum with the sum of the first window
        int maxSum = windowSum;
        
        // Step 3: Slide the window across the array
        for (int i = k; i < nums.size(); i++) {
            // Add the new element to the window and subtract the old element
            windowSum += nums[i] - nums[i - k];
            
            // Update maxSum if the current window sum is greater
            maxSum = max(maxSum, windowSum);
        }
        
        // Step 4: Calculate and return the maximum average
        return static_cast<double>(maxSum) / k;
    }
};