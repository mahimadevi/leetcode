class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> lastSeen; // To store the last seen index of each card value
        int minLength = INT_MAX; // To store the minimum window size
        
        for (int right = 0; right < cards.size(); right++) {
            int card = cards[right];
            
            // If the card value has been seen before
            if (lastSeen.find(card) != lastSeen.end()) {
                // Calculate the window size
                int windowSize = right - lastSeen[card] + 1;
                // Update the minimum window size
                minLength = min(minLength, windowSize);
            }
            
            // Update the last seen index of the card value
            lastSeen[card] = right;
        }
        
        // If no matching pair is found, return -1
        return (minLength == INT_MAX) ? -1 : minLength;
    }
};