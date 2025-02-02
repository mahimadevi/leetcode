class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int size = flowerbed.size();
        
        for (int i = 0; i < size; i++) {
            // Check if the current plot is empty
            if (flowerbed[i] == 0) {
                // Check if the left and right plots are also empty (or out of bounds)
                bool leftEmpty = (i == 0) || (flowerbed[i - 1] == 0);
                bool rightEmpty = (i == size - 1) || (flowerbed[i + 1] == 0);
                
                // If both left and right are empty, plant a flower
                if (leftEmpty && rightEmpty) {
                    flowerbed[i] = 1; // Plant the flower
                    count++; // Increment the count of planted flowers
                    
                    // If we've planted enough flowers, return true
                    if (count >= n) {
                        return true;
                    }
                }
            }
        }
        
        // Return true if we've planted at least n flowers, otherwise false
        return count >= n;
    }
};