class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0; // Pointer to write compressed characters
        int read = 0;  // Pointer to read the original characters

        while (read < n) {
            char currentChar = chars[read];
            int count = 0;

            // Count the number of consecutive repeating characters
            while (read < n && chars[read] == currentChar) {
                read++;
                count++;
            }

            // Write the character to the compressed array
            chars[write++] = currentChar;

            // Write the count if it's greater than 1
            if (count > 1) {
                // Convert the count to a string and write each digit
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[write++] = c;
                }
            }
        }

        // Return the new length of the compressed array
        return write;
    }
};