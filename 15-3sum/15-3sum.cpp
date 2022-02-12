class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> res;
        // skiping all continous same element, doing bcz to avoid duplicate triplets
        for(int i=0; i < n-2 ;i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                // two pointer's approach
                // a + b + c = 0, so we can make the equation like
                // b + c = -a;
                // low + high = -sum;
                int low=i+1;
                int high=nums.size()-1;
                int sum=-nums[i];
                
                while(low<high){
                    if(nums[low] + nums[high] == sum){
                        res.push_back({nums[i], nums[low], nums[high]});
                  
                        while(low<high && nums[low]==nums[low+1]) low++;
                        while(low<high && nums[high]==nums[high-1]) high--;
                        
                        low++;
                        high--;
                    }
                    else if(nums[low] + nums[high] < sum) 
                        low++;
                    else 
                        high--;
                }
            }
        }
        return res;
    }
};