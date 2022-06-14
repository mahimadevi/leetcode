class Solution {
public:
    int lcs(string& s1,int n, string& s2, int m,vector<vector<int>>& dp){
        if(min(n,m)==0)return 0;
        if(dp[n][m]!=-1)return dp[n][m];
        
        if(s1[n-1]==s2[m-1])return 1+lcs(s1,n-1,s2,m-1,dp);
        return dp[n][m]= max(lcs(s1,n-1,s2,m,dp),lcs(s1,n,s2,m-1,dp));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int len=lcs(word1,n,word2,m,dp);
        return (n+m)-2*len;
    }
};