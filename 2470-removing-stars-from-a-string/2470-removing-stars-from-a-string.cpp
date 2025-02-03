class Solution {
public:
    string removeStars(string s) {
        // Use a stack (or a string acting as a stack) to process characters
        string result;

        // Iterate through each character in the string
        for (char c : s) {
            if (c == '*') {
                // If the character is '*', remove the last added character (if any)
                if (!result.empty()) {
                    result.pop_back();
                }
            } else {
                // Otherwise, add the character to the result
                result.push_back(c);
            }
        }

        // Return the final processed string
        return result;
    }
};
