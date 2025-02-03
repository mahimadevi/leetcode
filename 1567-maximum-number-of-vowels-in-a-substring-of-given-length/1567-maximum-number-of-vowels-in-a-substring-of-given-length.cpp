class Solution {
public:
    int maxVowels(string s, int k) {
        // Define a set of vowels for easy checking
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        // Step 1: Count vowels in the first window of size k
        int windowVowelCount = 0;
        for (int i = 0; i < k; i++) {
            if (vowels.count(s[i])) {
                windowVowelCount++;
            }
        }
        
        // Step 2: Initialize maxVowelCount with the count of the first window
        int maxVowelCount = windowVowelCount;
        
        // Step 3: Slide the window across the string
        for (int i = k; i < s.size(); i++) {
            // If the new character is a vowel, increment the count
            if (vowels.count(s[i])) { 
                windowVowelCount++;
            }
            // If the character being left behind is a vowel, decrement the count
            if (vowels.count(s[i - k])) {
                windowVowelCount--;
            }
            // Update maxVowelCount if the current window has more vowels
            maxVowelCount = max(maxVowelCount, windowVowelCount);
        }
        
        // Step 4: Return the maximum vowel count
        return maxVowelCount;
    }
};

/*vowels.count(s[i]) : 
vowels is an unordered_set<char> that contains the vowels: {'a', 'e', 'i', 'o', 'u'}.
The count() method is a function provided by the unordered_set (and other STL containers like set and map).
vowels.count(s[i]) checks if the character s[i] exists in the vowels set.
*/