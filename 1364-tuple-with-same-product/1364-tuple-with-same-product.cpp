#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        // Step 1: Create a hash map to store the frequency of each product
        unordered_map<int, int> productCount;

        // Step 2: Iterate through all pairs and count their products
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int product = nums[i] * nums[j];
                productCount[product]++;
            }
        }

        // Step 3: Calculate the total number of valid tuples
        int result = 0;
        for (auto& [product, count] : productCount) {
            if (count >= 2) {
                // For each product that appears at least twice, calculate the number of tuples
                result += count * (count - 1) * 4;
            }
        }

        return result;
    }
};