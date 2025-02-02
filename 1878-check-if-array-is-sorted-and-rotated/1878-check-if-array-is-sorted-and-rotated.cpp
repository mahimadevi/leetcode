class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        // if an array is sorted and rotated then it can have atmost one violation(larger element->smaller element)
        for (int i = 1; i < n; i++)
            if (nums[i - 1] > nums[i])
                count++;
        
        // checks if the rotation is valid (last element must be smaller than first)
        if (nums[n - 1] > nums[0])
            count++;
        
        /* A valid rotated sorted array has at most one violation:
           1. Either a single rotation point within the array.
           2. Or a split at the boundary (last and first elements).
         If the total number of violations (count) exceeds 1, it indicates:
         1. The array is neither sorted nor a valid rotation of a sorted array.
         2. There are multiple breaks in the order, making it invalid. */
        return count <= 1;
    }
};
