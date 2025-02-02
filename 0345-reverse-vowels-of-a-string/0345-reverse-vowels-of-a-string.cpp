class Solution {
public:
    string reverseVowels(string s) {
        // Step 1: Create a vector to store the indices of vowels in the string
        vector<int> vec;
        int si = s.size(); // Get the size of the input string
        
        // Step 2: Loop through the string and find the vowels
        for (int i = 0; i < si; i++) {
            // Convert the character to lowercase to handle both cases ('A' and 'a')
            char cc = tolower(s[i]);

            // Check if the character is a vowel (a, e, i, o, u)
            if (cc == 'a' || cc == 'e' || cc == 'i' || cc == 'o' || cc == 'u') {
                // If it's a vowel, store its index in the vector
                vec.push_back(i);
            }
        }

        // Step 3: Get the total number of vowels
        int total = vec.size();

        // Step 4: Swap vowels from the beginning and end, moving toward the center
        // This will reverse the vowels in the string
        for (int i = 0; i < total / 2; i++) {
            // Swap the characters at the current vowel indices
            swap(s[vec[i]], s[vec[total - i - 1]]);
        }

        // Step 5: Return the modified string
        return s;
    }
};
