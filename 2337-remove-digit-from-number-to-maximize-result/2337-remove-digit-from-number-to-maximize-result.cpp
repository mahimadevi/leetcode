class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.length(); // Get the length of the number string
        int removeIndex = -1; // To store the index of the digit to remove
        
        // Traverse the string to find the best occurrence to remove
        for (int i = 0; i < n; i++) {
            if (number[i] == digit) {
                // If this is the last occurrence, mark it for removal
                if (i == n - 1) {
                    removeIndex = i;
                    break;
                }
                // If the next character is greater than the current digit, remove this occurrence
                if (number[i + 1] > digit) {
                    removeIndex = i;
                    break;
                }
                // Otherwise, keep track of the last occurrence
                removeIndex = i;
            }
        }
        
        // Remove the selected occurrence of the digit
        string result = number.substr(0, removeIndex) + number.substr(removeIndex + 1);
        return result; // Return the resulting string
    }
};