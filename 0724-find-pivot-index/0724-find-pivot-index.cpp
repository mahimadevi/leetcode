#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0; // Total sum of all elements in the array
        int leftSum = 0;  // Sum of elements to the left of the current index

        // Calculate the total sum of the array
        for (int num : nums) {
            totalSum += num;
        }

        // Iterate through the array to find the pivot index
        for (int i = 0; i < nums.size(); i++) {
            // Right sum = total sum - left sum - current element
            int rightSum = totalSum - leftSum - nums[i];

            // Check if left sum equals right sum
            if (leftSum == rightSum) {
                return i; // Return the current index as the pivot index
            }

            // Update the left sum for the next iteration
            leftSum += nums[i];
        }

        return -1; // If no pivot index is found, return -1
    }
};