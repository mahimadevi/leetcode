class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(),initialProduct=1,res,prod=1,count=0;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                count++;
            else
                prod=prod*nums[i];
        }
        for(int i=0;i<n;i++)
        {
            if(count>1) //ek se zyada 0 hue to sb zero honge
                res=0;
            
            else if(count==1 && nums[i]!=0)//agr sirf ek hi 0 hua to baaki sbhi jagah 0 product
                res=0;
            
            else if(count==1 && nums[i]==0)//agr sirf ek hi 0 hua to ussi index pr sirf value hogi baaki jagah 0 hoga
                res=prod;
            
            else    //baaki sbhi cases mein product/nums[i] hoga
                res=prod/nums[i];
            
            ans.push_back(res);
        }
        return ans;
    }
};