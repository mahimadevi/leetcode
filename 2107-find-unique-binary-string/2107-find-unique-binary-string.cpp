class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string result;
        int n = nums.size();
        
        // Construct the result string
        for (int i = 0; i < n; i++) {
            // Choose the opposite of the i-th character of the i-th string
            char currentChar = nums[i][i];
            result += (currentChar == '0') ? '1' : '0';
        }
        
        return result;
    }
};