//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string s, string t)
    {
        
        // Your code here
        if(s.size()!=t.size()) return 0;
        unordered_map<char,char>mpp1,mpp2;
        for(int i=0;i<s.size();i++){
            if(mpp1[s[i]] && mpp1[s[i]]!=t[i]) return 0;
            if(mpp2[t[i]] && mpp2[t[i]]!=s[i]) return 0;
            mpp1[s[i]]=t[i];
            mpp2[t[i]]=s[i];
        }
        return 1;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends