//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautyFrequency(int freq[]){
        int mini=INT_MAX;
        int maxi=INT_MIN;
        
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                mini=min(mini,freq[i]);
                maxi=max(maxi,freq[i]);
            }
        }
        return (maxi-mini);
    }
  
    int beautySum(string s) {
        // Your code goes here
        int ans=0;
        
        for(int i=0;i<s.size();i++){
            int freq[26]={0};
            for(int j=i;j<s.size();j++){
                freq[s[j]-'a']++;
                ans+=beautyFrequency(freq);
            }
        }
        return ans;
        
    
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
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends