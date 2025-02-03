class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0; // Left boundary of the window
        int right = 0; // Right boundary of the window
        int zeroCount = 0; // Count of 0's in the current window
        int maxLen = 0; // Maximum length of the window with at most k 0's

        // Slide the window using the right pointer
        for (right = 0; right < nums.size(); right++) {
            // If the current element is 0, increment zeroCount
            if (nums[right] == 0) {
                zeroCount++;
            }

            // If zeroCount exceeds k, shrink the window from the left
            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--; // Decrement zeroCount if the left element is 0
                }
                left++; // Move the left pointer to the right
            }

            // Update maxLen with the current window size
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};