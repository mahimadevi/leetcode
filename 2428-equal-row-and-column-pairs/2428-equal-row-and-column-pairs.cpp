#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int count = 0;

        // Custom hash function for vector<int>
        struct VectorHash {
            size_t operator()(const vector<int>& v) const {
                size_t hash = 0;
                for (int num : v) {
                    hash ^= hash * 31 + num; // Combine hash values
                }
                return hash;
            }
        };

        // Use unordered_map with the custom hash function
        unordered_map<vector<int>, int, VectorHash> rowMap;

        // Store each row's frequency
        for (int i = 0; i < n; i++) {
            rowMap[grid[i]]++;
        }

        // Compare each column with stored rows
        for (int j = 0; j < n; j++) {
            vector<int> col;
            for (int i = 0; i < n; i++) {
                col.push_back(grid[i][j]);
            }

            // If column exists in rowMap, add its count
            if (rowMap.find(col) != rowMap.end()) {
                count += rowMap[col];
            }
        }

        return count;
    }
};
