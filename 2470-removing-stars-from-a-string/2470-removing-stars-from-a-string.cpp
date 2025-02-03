// class Solution {
// public:
//     string removeStars(string s) {
//         // Use a stack (or a string acting as a stack) to process characters
//         string result;

//         // Iterate through each character in the string
//         for (char c : s) {
//             if (c == '*') {
//                 // If the character is '*', remove the last added character (if any)
//                 if (!result.empty()) {
//                     result.pop_back();
//                 }
//             } else {
//                 // Otherwise, add the character to the result
//                 result.push_back(c);
//             }
//         }

//         // Return the final processed string
//         return result;
//     }
// };
class Solution {
public:
    string removeStars(string s) {
        int i = 0, j = 0; // `i` iterates through the string, `j` keeps track of valid characters
        
        for (i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                // If we find a '*', remove the last added character by moving `j` back
                j--;
            } else {
                // Otherwise, store the current character at position `j` and move `j` forward
                s[j++] = s[i];
            }
        }
        
        // Return only the valid part of the string (up to `j`)
        return s.substr(0, j);
    }
};
