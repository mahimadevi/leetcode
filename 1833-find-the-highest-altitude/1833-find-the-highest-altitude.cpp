#include <vector>
#include <algorithm> // For std::max
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currentAltitude = 0; // Start at altitude 0
        int maxAltitude = 0;     // Track the highest altitude reached

        // Iterate through the gain array
        for (int i = 0; i < gain.size(); i++) {
            currentAltitude += gain[i]; // Update the current altitude
            maxAltitude = max(maxAltitude, currentAltitude); // Update the maximum altitude
        }

        return maxAltitude; // Return the highest altitude reached
    }
};