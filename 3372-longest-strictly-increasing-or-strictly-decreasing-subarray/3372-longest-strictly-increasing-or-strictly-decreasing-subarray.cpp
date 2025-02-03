class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxInc = 0, maxDec = 0, inc = 0, dec = 0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]<nums[i+1]){
                inc++;
                maxInc = max(maxInc,inc);
                dec=0;
            }else if(nums[i]>nums[i+1]){
                dec++;
                maxDec = max(maxDec,dec);
                inc=0;
            }else if(nums[i]==nums[i+1]){
                inc=0;
                dec=0;
            }
        }
        return max(maxInc+1, maxDec+1);
    }
};