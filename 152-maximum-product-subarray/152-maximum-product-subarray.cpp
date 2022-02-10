class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProduct=nums[0],max_so_far=nums[0],min_so_far=nums[0];
        for(int i=1;i<n;i++)
        {
            int temp=max_so_far;
            max_so_far=max({nums[i],max_so_far*nums[i],min_so_far*nums[i]});
            min_so_far=min({nums[i],temp*nums[i],min_so_far*nums[i]});
            maxProduct=max(maxProduct,max_so_far);
        }
        return maxProduct;
    }
};
// agr hmara abhi tak ka product positive hai, aur abhi jissey multiply kr rhe wo bhi positive hai to hmara product aur increase hoga.
//agr hmara abhi tak product negative hai, aur abhi jissey multiply kr rhe wo bhi negative hai to hmara product aur increase hoga, mgr agr bhi jissey multiply kr rhe positive hua to aise mein hmara product decrease hoga.
// agr hmara abhi tak ka product zero hai,aur abhi jissey multiply kr rhw wo positive ya negative kuch bhhi to hmara product 0 hi aayega.

//hmne 3 variables banaye, max_so_far jisme hm abhi tak ki max value store krenge, min_so_far jisme hm abhi tak ki min value store krenge, and maxProduct jisme hm overall max value store krenge.

//agr abhi bhi nhi samjh aa rha to ye video dekh lena: https://www.youtube.com/watch?v=hJ_Uy2DzE08&ab_channel=KnowledgeCenter