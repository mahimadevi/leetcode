//{ Driver Code Starts
#include <stdio.h>
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int select(int arr[], int i);
void selectionSort(int arr[], int n);
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
  
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      
    selectionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends


int select(int arr[], int i)
{
    // code here such that selecionSort() sorts arr[]
    return 0;
}


void selectionSort(int arr[], int n)
{
   int min_idx,i,j;

  for (i=0 ; i<n-1;i++){

  min_idx=i;

  for (int j= i+1;j<n;j++)

  {

      if (arr[j]<arr[min_idx])

      {

          min_idx = j;

      }      

  }      

      int temp = arr[min_idx];

      arr[min_idx]=arr[i];

      arr[i]=temp;

  }
}