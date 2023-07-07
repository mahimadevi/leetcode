//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maxDepth(string s) {
        // code here
        int max=0,count=0;
        
        for(int i=0;i<s.size();i++){
            if(count>max)
            max=count;
            if(s[i]=='(' && count>=0)
            count++;
            else if(s[i]==')' && count>=1)
            count--;
        }
        return max;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        int ans = obj.maxDepth(s);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends