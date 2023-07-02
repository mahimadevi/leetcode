//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long getHoursToEatAll(int n, vector<int>& piles, int bananasPerHour){
        long long totalHoursToEat=0;
        for(int i=0;i<n;i++){
            int hoursToEatAll=ceil(piles[i]/double(bananasPerHour));
            totalHoursToEat+=hoursToEatAll;
        }
        return totalHoursToEat;
    }
    int Solve(int N, vector<int>& piles, int H) {
        // Code here
        int low=1, high=*(max_element(piles.begin(),piles.end()));
        int ans=-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            long long totalHoursToEatAll=getHoursToEatAll(N,piles,mid);
            if(totalHoursToEatAll<=H){
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends