class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // Step 1: Check if the lengths are the same
        if (word1.size() != word2.size()) {
            return false;
        }

        // Step 2: Check if the sets of characters are the same
        vector<int> count1(26, 0); // Frequency count for word1
        vector<int> count2(26, 0); // Frequency count for word2
        vector<bool> exists1(26, false); // Characters present in word1
        vector<bool> exists2(26, false); // Characters present in word2

        // Populate frequency counts and character existence
        for (char c : word1) {
            count1[c - 'a']++;
            exists1[c - 'a'] = true;
        }
        for (char c : word2) {
            count2[c - 'a']++;
            exists2[c - 'a'] = true;
        }

        // Check if the sets of characters are the same
        if (exists1 != exists2) {
            return false;
        }

        // Step 3: Check if the frequency counts are the same
        // Sort the frequency counts and compare
        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());

        return count1 == count2;
    }
};