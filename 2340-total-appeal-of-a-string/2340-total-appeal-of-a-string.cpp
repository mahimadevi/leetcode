class Solution {
public:
    long long appealSum(string s) {
        long long totalAppeal = 0; // To store the total appeal
        int n = s.length(); // Length of the string
        vector<int> lastOccurrence(26, -1); // To store the last occurrence index of each character
        
        // Traverse the string and calculate the contribution of each character
        for (int i = 0; i < n; i++) {
            char currentChar = s[i];
            int lastIndex = lastOccurrence[currentChar - 'a']; // Last occurrence index of the current character
            // Calculate the number of substrings where currentChar contributes to the appeal
            totalAppeal += (long long)(i - lastIndex) * (n - i); // Use long long to prevent overflow
            // Update the last occurrence index of the current character
            lastOccurrence[currentChar - 'a'] = i;
        }
        
        return totalAppeal; // Return the total appeal
    }
};
