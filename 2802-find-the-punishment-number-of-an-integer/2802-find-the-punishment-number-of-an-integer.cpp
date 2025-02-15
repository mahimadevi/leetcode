class Solution {
public:
    int punishmentNumber(int n) {
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            int square = i * i;
            if (canPartition(square, i)) {
                result += square;
            }
        }
        return result;
    }
    
private:
    bool canPartition(int num, int target) {
        std::string s = std::to_string(num);
        return backtrack(s, 0, target, 0);
    }
    
    bool backtrack(const std::string& s, int index, int target, int currentSum) {
        if (index == s.length()) {
            return currentSum == target;
        }
        for (int i = index; i < s.length(); ++i) {
            std::string substring = s.substr(index, i - index + 1);
            int num = std::stoi(substring);
            if (backtrack(s, i + 1, target, currentSum + num)) {
                return true;
            }
        }
        return false;
    }
};