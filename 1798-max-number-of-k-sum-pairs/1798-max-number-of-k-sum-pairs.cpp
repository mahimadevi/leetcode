#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // Hash map to store the frequency of each number
        int operations = 0; // Counter for the number of operations

        for (int num : nums) {
            int complement = k - num; // The number needed to form a pair with the current number

            // Check if the complement exists in the hash map
            if (freq[complement] > 0) {
                operations++; // Increment the operation count
                freq[complement]--; // Decrease the frequency of the complement
            } else {
                freq[num]++; // If no complement found, increase the frequency of the current number
            }
        }

        return operations; // Return the total number of operations
    }
};