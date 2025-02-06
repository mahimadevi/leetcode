class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();    // Length of the spells array
        int m = potions.size();   // Length of the potions array
        vector<int> result(n, 0); // Result vector to store the number of successful pairs for each spell
        
        // Step 1: Sort the potions array in ascending order
        sort(potions.begin(), potions.end());
        
        // Step 2: For each spell, find the number of potions that form successful pairs with it
        for (int i = 0; i < n; i++) {
            long long spellStrength = spells[i]; // Get the strength of the current spell
            long long target = (success + spellStrength - 1) / spellStrength; // Calculate the minimum potion strength required for success
            
            // Step 3: Use binary search to find the first potion that meets the required strength
            int left = 0, right = m - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2; // Mid-point of the potion array
                if (potions[mid] >= target) {  // If the potion strength is sufficient
                    right = mid - 1;           // We look for smaller potions in the left side
                } else {
                    left = mid + 1;            // We look for stronger potions in the right side
                }
            }
            
            // Step 4: After binary search, left will be the index of the first successful potion
            result[i] = m - left; // The number of successful pairs for this spell is the number of potions left from 'left' to the end of the potions array
        }

        return result; // Return the result vector
    }
};
