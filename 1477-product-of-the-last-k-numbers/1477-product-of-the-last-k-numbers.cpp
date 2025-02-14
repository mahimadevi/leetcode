#include <vector>
using namespace std;

class ProductOfNumbers {
private:
    vector<int> prefixProducts; // Stores the prefix products of the stream
    int lastZeroIndex;          // Tracks the index of the last zero added

public:
    ProductOfNumbers() {
        prefixProducts = {1};   // Initialize with 1 to handle edge cases
        lastZeroIndex = -1;     // No zero added yet
    }

    void add(int num) {
        if (num == 0) {
            // Reset the prefix products array
            prefixProducts = {1};
            lastZeroIndex = prefixProducts.size() - 1;
        } else {
            // Multiply the last prefix product by the new number
            prefixProducts.push_back(prefixProducts.back() * num);
        }
    }

    int getProduct(int k) {
        int n = prefixProducts.size();
        if (lastZeroIndex >= n - k) {
            // If the last k elements include a zero, return 0
            return 0;
        }
        // Return the product of the last k elements
        return prefixProducts.back() / prefixProducts[n - k - 1];
    }
};

/**
 * Example Walkthrough:
 * Input: ["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
 *        [[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]
 * 
 * Execution:
 * 1. Initialize: prefixProducts = [1], lastZeroIndex = -1
 * 2. add(3): prefixProducts = [1, 3], lastZeroIndex = -1
 * 3. add(0): prefixProducts = [1], lastZeroIndex = 0
 * 4. add(2): prefixProducts = [1, 2], lastZeroIndex = 0
 * 5. add(5): prefixProducts = [1, 2, 10], lastZeroIndex = 0
 * 6. add(4): prefixProducts = [1, 2, 10, 40], lastZeroIndex = 0
 * 7. getProduct(2): 40 / 2 = 20
 * 8. getProduct(3): 40 / 1 = 40
 * 9. getProduct(4): 0 (since lastZeroIndex >= n - k)
 * 10. add(8): prefixProducts = [1, 8], lastZeroIndex = 0
 * 11. getProduct(2): 8 / 1 = 8
 */