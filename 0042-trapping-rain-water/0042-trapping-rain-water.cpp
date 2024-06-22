class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0, right=n-1;
        int res=0, maxLeft=0,maxRight=0;
        while(left <= right){
            if(height[left] <= height[right]){
                if(maxLeft<=height[left]) maxLeft=height[left];
                else{
                    res=res+maxLeft-height[left];
                }
                left++;
            }
            else{
                if(height[right]>=maxRight) maxRight=height[right];
                else{
                    res=res+maxRight-height[right];
                }
                right--;
            }
        }
        return res;
    }
};