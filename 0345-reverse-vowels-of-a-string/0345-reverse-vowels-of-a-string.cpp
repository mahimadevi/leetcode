class Solution {
public:
    string reverseVowels(string s) {
        // Set of vowels (both lowercase and uppercase)
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        // Two pointers: left and right
        int left = 0, right = s.size() - 1;
        
        while (left < right) {
            // Move left pointer to the next vowel
            while (left < right && vowels.find(s[left]) == vowels.end()) {
                left++;
            }
            // Move right pointer to the previous vowel
            while (left < right && vowels.find(s[right]) == vowels.end()) {
                right--;
            }
            // Swap the vowels
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        
        return s;
    }
};