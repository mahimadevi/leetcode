class Solution {
public:
    string reverseVowels(string s) {
        // Step 1: Create a vector to store the indices of vowels in the string.
        vector<int> vec;

        // Step 2: Loop through the string to find all vowels and store their indices.
        int si = s.size(); // Get the length of the string.
        for (int i = 0; i < si; i++) {
            // Convert the current character to lowercase to handle both uppercase and lowercase vowels.
            char cc = tolower(s[i]);

            // Check if the character is a vowel.
            if (cc == 'a' || cc == 'e' || cc == 'i' || cc == 'o' || cc == 'u') {
                // If it's a vowel, store its index in the vector.
                vec.push_back(i);
            }
        }

        // Step 3: Get the total number of vowels found.
        int total = vec.size();

        // Step 4: Swap the vowels from the start and end of the vector.
        // We only need to swap up to half the total number of vowels.
        for (int i = 0; i < total / 2; i++) {
            // Swap the vowel at position `i` with the vowel at position `total - i - 1`.
            swap(s[vec[i]], s[vec[total - i - 1]]);
        }

        // Step 5: Return the modified string with reversed vowels.
        return s;
    }
};