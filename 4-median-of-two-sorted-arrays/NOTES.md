TAKE U FORWARD YT SOLUTION:https://www.youtube.com/watch?v=NTop3VTjmxk&ab_channel=takeUforward
class Solution {
public:
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
int n1 = nums1.size(); //nums1=A
int n2 = nums2.size(); //nums2=B
int total = (n1+n2)/2;
int half = total/2;
float res = 0;
if(n2<n1)
return findMedianSortedArrays(nums2, nums1);
int l = 0, r = n1-1;
while(l<=r){
int i=(l+r)/2,j=half-i-2,Aleft,Aright,Bleft,Bright;
if(i>0)Aleft = nums1[i]; else Aleft = INT_MIN;
if(i+1<n1)Aright = nums1[i+1]; else Aright = INT_MIN;
if(j>0)Bleft = nums2[j]; else Bleft = INT_MAX;
if(j+1<n2)Bright = nums2[j+1]; else Bright = INT_MAX;
//If partition is correct
if(Aleft <= Bright  && Bleft <= Aright){
if(total % 2 != 0)         //odd
res = min(Aright, Bright);
//if even
else{
int left = max(Aleft, Bleft);
int right = min(Aright, Bright);
res = (left+right)/2;}
}
else if(Aleft > Bright) r = i-1;
else l = i+1;
}
return res;
}
};