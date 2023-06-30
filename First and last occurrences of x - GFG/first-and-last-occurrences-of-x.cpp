//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    int i=0,j=n-1;
    int start=-1,end=-1;
    
    vector<int>ans;
    
    while(i<=j){
        int mid=(i+j)/2;
        
        if(arr[mid]==x){
            int temp=mid;
            
            while(mid>0 && arr[mid-1]==x)
            mid--;
            start=mid;
            
            while(temp<n-1 && arr[temp+1]==x)
            temp++;
            end=temp;
            
            ans.push_back(start);
            ans.push_back(end);
            return ans;
        }
        
        else if(arr[mid]>x)
        j=mid-1;
        
        else
        i=mid+1;
    }
    
    ans.push_back(-1);
    ans.push_back(-1);
    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends