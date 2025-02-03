class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0; // Left boundary of the window
        int right = 0; // Right boundary of the window
        int zeroCount = 0; // Count of 0's in the current window
        int maxLen = 0; // Maximum length of the window with at most one 0

        // Slide the window using the right pointer
        for (right = 0; right < nums.size(); right++) {
            // If the current element is 0, increment zeroCount
            if (nums[right] == 0) {
                zeroCount++;
            }

            // If zeroCount exceeds 1, shrink the window from the left
            while (zeroCount > 1) {
                if (nums[left] == 0) {
                    zeroCount--; // Decrement zeroCount if the left element is 0
                }
                left++; // Move the left pointer to the right
            }

            // Update maxLen with the current window size
            maxLen = max(maxLen, right - left + 1);
        }

        // Since we need to delete one element, subtract 1 from maxLen
        // If maxLen == nums.size(), it means all elements are 1, so we must delete one
        return maxLen == nums.size() ? maxLen - 1 : maxLen - 1;
    }
};