class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc]; // Store the original color of the starting pixel
        if (originalColor == color) return image; // If the new color is the same as the original, no changes are needed
        
        int m = image.size(); // Number of rows in the image
        int n = image[0].size(); // Number of columns in the image
        
        // Perform DFS to flood fill the image
        dfs(sr, sc, m, n, originalColor, color, image);
        
        return image; // Return the modified image
    }

private:
    void dfs(int row, int col, int m, int n, int originalColor, int newColor, vector<vector<int>>& image) {
        // Base case: If the current pixel is out of bounds or not of the original color, return
        if (row < 0 || row >= m || col < 0 || col >= n || image[row][col] != originalColor) {
            return;
        }
        
        // Change the color of the current pixel
        image[row][col] = newColor;
        
        // Recursively perform DFS on the 4 adjacent pixels (up, down, left, right)
        dfs(row + 1, col, m, n, originalColor, newColor, image); // Down
        dfs(row - 1, col, m, n, originalColor, newColor, image); // Up
        dfs(row, col + 1, m, n, originalColor, newColor, image); // Right
        dfs(row, col - 1, m, n, originalColor, newColor, image); // Left
    }
};