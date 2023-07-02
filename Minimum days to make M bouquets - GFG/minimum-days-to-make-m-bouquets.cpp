//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool check(int presentDay, vector<int>& bloomDay, int requiredBouquet, int requiredFlower){
        int flowerCount=0;
        int bouquetCount=0;
        
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=presentDay){
                flowerCount++;
                if(flowerCount==requiredFlower){
                    bouquetCount++;
                    flowerCount=0;
                }
            }
            else
            flowerCount=0;
        }
        
        if(bouquetCount>=requiredBouquet) return true;
        else return false;
    }
  
  
    int solve(int M, int K, vector<int> &bloomDay){
      // Code here
      
      if(M*K > bloomDay.size()) return -1;
      
      int low=*min_element(bloomDay.begin(),bloomDay.end());
      int high=*max_element(bloomDay.begin(),bloomDay.end());
      
      while(low<high){
          int mid=low+(high-low)/2;
          
          if(check(mid,bloomDay,M,K)) high=mid;
          else low=mid+1;
      }
      return low;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends