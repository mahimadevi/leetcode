class Solution {
public:
    int BS(vector<int>&nums, int start, int end, int value)
    {
        if(start>end)
            return -1;
        int mid=(start+end)/2;
        if(nums[mid]==value)  
            return mid;
        if(nums[start]<=nums[mid]) //if mid lies in right sequence
        {
            if(value >= nums[start] && value <= nums[mid])
                return BS(nums, start, mid-1, value);
            return BS(nums, mid+1, end, value);
        }
        if(value >= nums[mid] && value <= nums[end])  //if mid lies in left sequence
            return BS(nums, mid+1, end, value);
        return BS(nums, start, mid-1, value);
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return BS(nums,0,n-1,target);
    }
};