class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProduct=nums[0],max_so_far=nums[0],min_so_far=nums[0];
        for(int i=1;i<n;i++)
        {
            int temp=max_so_far;
            max_so_far=max({nums[i],max_so_far*nums[i],min_so_far*nums[i]});
            min_so_far=min({nums[i],temp*nums[i],min_so_far*nums[i]});
            maxProduct=max(maxProduct,max_so_far);
        }
        return maxProduct;
    }
};