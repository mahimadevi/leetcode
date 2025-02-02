class Solution {
public:
    bool isSubsequence(string s, string t) {
        // Initialize pointers for s and t
        int sPointer = 0, tPointer = 0;

        // Traverse both strings
        while (sPointer < s.length() && tPointer < t.length()) {
            // If characters match, move sPointer forward
            if (s[sPointer] == t[tPointer]) {
                sPointer++;
            }
            // Always move tPointer forward
            tPointer++;
        }

        // If sPointer reached the end of s, s is a subsequence of t
        return sPointer == s.length();
    }
};