class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); // Number of rows
        int m = grid[0].size(); // Number of columns

        queue<pair<pair<int, int>, int>> q; // Queue to store rotten oranges and their time
        vector<vector<int>> vis(n, vector<int>(m, 0)); // Visited matrix to track rotten oranges

        int fresh = 0; // Count of fresh oranges

        // Initialize the queue and visited matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) { // If the orange is rotten
                    q.push({{i, j}, 0}); // Push the rotten orange into the queue
                    vis[i][j] = 2; // Mark it as rotten in the visited matrix
                } else if (grid[i][j] == 1) { // If the orange is fresh
                    fresh++; // Increment the count of fresh oranges
                }
            }
        }

        int time = 0; // To store the total time required
        vector<int> dRow = {-1, 0, +1, 0}; // Directions for row (up, right, down, left)
        vector<int> dCol = {0, +1, 0, -1}; // Directions for column (up, right, down, left)

        // Perform BFS
        while (!q.empty()) {
            int row = q.front().first.first; // Current row
            int col = q.front().first.second; // Current column
            int t = q.front().second; // Current time
            time = max(t, time); // Update the total time
            q.pop(); // Remove the current orange from the queue

            // Check all 4 adjacent cells
            for (int i = 0; i < 4; i++) {
                int nrow = row + dRow[i]; // New row
                int ncol = col + dCol[i]; // New column

                // If the adjacent cell is within bounds, is fresh, and not visited
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1}); // Push the new rotten orange into the queue
                    vis[nrow][ncol] = 2; // Mark it as rotten in the visited matrix
                    fresh--; // Decrease the count of fresh oranges
                }
            }
        }

        // If there are still fresh oranges left, return -1
        if (fresh > 0) return -1;

        // Otherwise, return the total time required
        return time;
    }
};