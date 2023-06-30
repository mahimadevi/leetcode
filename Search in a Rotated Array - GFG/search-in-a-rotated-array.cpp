//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int nums[], int start, int end, int value){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        
        if(start>end)
            return -1;
        int mid=(start+end)/2;
        if(nums[mid]==value)  
            return mid;
        if(nums[start]<=nums[mid]) //if mid lies in right sequence
        {
            if(value >= nums[start] && value <= nums[mid])
                return search(nums, start, mid-1, value);
            return search(nums, mid+1, end, value);
        }
        if(value >= nums[mid] && value <= nums[end])  //if mid lies in left sequence
            return search(nums, mid+1, end, value);
        return search(nums, start, mid-1, value);
    }
    

};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends