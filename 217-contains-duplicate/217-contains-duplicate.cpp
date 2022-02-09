class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size(), count=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                count=1;
                break;
            }
            else 
                count=0;
        }
        if(count==1)
            return true;
        else 
            return false;
    }
};