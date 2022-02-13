class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int maxh=0;
        while(left<right)
        {
            int minh = min(nums[left], nums[right]);
            maxh = max(maxh, minh*(right-left));
            if(nums[left]<nums[right]) left++;
            else right--;
        }
        return maxh;
    }
};