//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string getPal(string s, int left, int right){
        while(left>=0 && right<s.size()){
            if(s[left]!=s[right])
            break;
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }
  
    string longestPalin (string s) {
        // code here
        if(s.empty()) return 0;
        string longest;
        
        for(int i=0;i<s.size();i++){
            string odd=getPal(s,i,i);
            if(odd.size()>longest.size())
            longest=odd;
        }
        for(int i=0;i<s.size();i++){
            string even=getPal(s,i,i+1);
            if(even.size()>longest.size())
            longest=even;
        }
        
        return longest;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends