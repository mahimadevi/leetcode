class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int l=0; //l is to count length of leftprefix
        int r=arr.size()-1;  //to count length of rightsuffix
        int n=arr.size(); 
        //the monotone increasing prefix [a[0] <= ... a[i] | ...]
        while(l < r and arr[l+1] >= arr[l]){
             l+=1;
        }
        //if l=length of array means that whole array is sorted so no need of removing
        if(l == n-1) return 0;
        //the monotone increasing suffix [... | a[j] <= ... a[n]]
        while( r > 0 and arr[r-1] <= arr[r]){
              r-=1;
        }
        int lentoRemove = min((n-l-1), r);
//prefix aur sufix ki length ka minimum le rhe, jo chota hua, to utni length ka subarray remove krna hoga
        for(int i=0;i<l+1;i++){
            if(arr[i] <= arr[r])
                lentoRemove = min(lentoRemove,(r-i-1));
            else if(r < n-1)
                 r += 1;
            else
                break;
        }
        return lentoRemove;
    }
};