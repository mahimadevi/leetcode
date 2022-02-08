class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
       int mins=20000,profit=0,i;
        for(i=0;i<n;i++)
        {
            
            if(mins>prices[i])
                mins=prices[i];
            if(profit<prices[i]-mins)
                profit=prices[i]-mins;
        }
        return profit;
    }
   
};