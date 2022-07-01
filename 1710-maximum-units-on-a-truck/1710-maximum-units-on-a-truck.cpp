class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>& a,vector<int>& b){
            return a[1]>b[1];
        });
        
        int maxUnits=0;
        for(auto& p: boxTypes){
            if(truckSize<=0) break;
            maxUnits = maxUnits + min(truckSize, p[0])*p[1];
            truckSize = truckSize-p[0];
        }
        return maxUnits;
    }
};