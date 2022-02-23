class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int count=0,max=0,res=0;
        for(int i=0;i<n;i++){
            if(arr[i]>max)
                max=arr[i];
            if(max==i)
                count++;
        }
        return count;
    }
};


/*
it means that all elemetns who are smaller than i are left to it and bigger are right to it .

 int maxChunksToSorted(vector<int>& v) 
    {
        //sum1 is sum of 0.........i
        //co is sum of v[0],v[1].......v[i]
        int i,co=0,sum1=0,ans=0;
        for(i=0;i<v.size();i++)
        {
            sum1+=i;
            co+=v[i];
            if(sum1==co)
                ans++;
        }
        return ans;
    }
*/