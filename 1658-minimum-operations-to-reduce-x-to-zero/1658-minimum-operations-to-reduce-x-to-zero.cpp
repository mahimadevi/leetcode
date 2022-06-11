class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
       int sum = 0, l = 0, r = 0, maxLen = -1, currSum = 0;
        int n=nums.size();
        for(int i = 0; i<n; i++){
            sum += nums[i];
        }
        
        for(l = 0, r = 0; r<n; r++){
            currSum += nums[r];
            while(l<=r && currSum>sum-x){
                currSum -= nums[l++];
            }
            if(currSum == sum-x){
                maxLen = max(maxLen, r-l+1);
            }
        }
        return maxLen == -1 ? -1 : n-maxLen;
    }
};