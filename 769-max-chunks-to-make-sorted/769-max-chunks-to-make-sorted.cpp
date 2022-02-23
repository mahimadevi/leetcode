class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int count=0,max=0,res=0;
        for(int i=0;i<n;i++){
            if(arr[i]>max)
                max=arr[i];
            if(max==i)
                count++;
        }
        return count;
    }
};