class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Handle edge case where the string is empty
        if (s.size() == 0) return s;

        // Step 2: Use a stack to store words
        stack<string> stack;

        // Step 3: Traverse the string to extract words
        for (int i = 0; i < s.size(); i++) {
            string word; // Temporary variable to store a word

            // Skip spaces in the string
            if (s[i] == ' ') continue;

            // Extract continuous non-space characters to form a word
            while (i < s.size() && s[i] != ' ') {
                word += s[i]; // Add the current character to the word
                i++;          // Move to the next character
            }

            // Push the extracted word onto the stack
            stack.push(word);
        }

        // Step 4: Build the result string by popping words from the stack
        string result;
        while (!stack.empty()) {
            // Append the top word from the stack to the result
            result += stack.top();
            stack.pop(); // Remove the top word from the stack

            // Add a space after each word (except the last one)
            if (!stack.empty()) result += " ";
        }

        // Step 5: Return the final reversed string
        return result;
    }
};