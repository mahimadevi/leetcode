class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // Find the maximum number of candies among all kids
        int maxCandies = *max_element(candies.begin(), candies.end());
        
        // Initialize the result vector
        vector<bool> result;
        
        // Check for each kid if adding extraCandies makes their candies >= maxCandies
        for (int candy : candies) {
            result.push_back(candy + extraCandies >= maxCandies);
        }
        
        return result;
    }
};