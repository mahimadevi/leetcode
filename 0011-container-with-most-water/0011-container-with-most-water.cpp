class Solution {
public:
    int maxArea(vector<int>& height) {
        // Two-pointer approach: left pointer at the beginning and right pointer at the end of the array
        int left = 0, right = height.size() - 1;
        int maxArea = 0; // Variable to store the maximum area
        
        // Loop until the left pointer crosses the right pointer
        while (left < right) {
            // Calculate the area formed by the lines at the current left and right pointers
            int width = right - left; // Distance between the two lines
            int minHeight = min(height[left], height[right]); // The height of the container is determined by the shorter line
            int area = width * minHeight; // Area = width * height
            
            // Update maxArea if the current area is larger
            maxArea = max(maxArea, area);
            
            // Move the pointer pointing to the shorter line, because the area could be larger if we find a taller line
            if (height[left] < height[right]) {
                left++; // Move left pointer to the right to find a taller line
            } else {
                right--; // Move right pointer to the left to find a taller line
            }
        }
        
        // Return the maximum area found
        return maxArea;
    }
};
