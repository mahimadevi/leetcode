class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        // Step 1: Initialize data structures
        unordered_map<int, int> ballToColor; // Maps ball to its current color
        unordered_map<int, int> colorFreq;   // Maps color to its frequency
        vector<int> result;                  // Stores the result after each query
        int distinctColors = 0;              // Tracks the number of distinct colors

        // Step 2: Process each query
        for (const auto& query : queries) {
            int ball = query[0]; // Ball to be colored
            int color = query[1]; // New color

            // Step 3: If the ball already has a color, update its frequency
            if (ballToColor.find(ball) != ballToColor.end()) {
                int oldColor = ballToColor[ball];
                colorFreq[oldColor]--; // Decrement the frequency of the old color
                if (colorFreq[oldColor] == 0) {
                    distinctColors--; // If frequency becomes 0, decrement distinctColors
                }
            }

            // Step 4: Assign the new color to the ball
            ballToColor[ball] = color;
            colorFreq[color]++; // Increment the frequency of the new color
            if (colorFreq[color] == 1) {
                distinctColors++; // If frequency becomes 1, increment distinctColors
            }

            // Step 5: Append the current count of distinct colors to the result
            result.push_back(distinctColors);
        }

        // Step 6: Return the result
        return result;
    }
};

/**
 * Explanation of the Code:
 * 1. We use two hash maps:
 *    - `ballToColor` to store the current color of each ball.
 *    - `colorFreq` to store the frequency of each color.
 * 2. For each query:
 *    - If the ball already has a color, we decrement its frequency and update `distinctColors`.
 *    - We assign the new color to the ball and update its frequency and `distinctColors`.
 * 3. After processing each query, we append the current count of distinct colors to the result.
 */