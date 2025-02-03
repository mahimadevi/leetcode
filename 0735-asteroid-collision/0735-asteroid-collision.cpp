#include <vector>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack; // This will store the surviving asteroids

        for (int ast : asteroids) {
            bool destroyed = false; // Flag to check if the current asteroid gets destroyed

            // Check for collisions only if the stack has a positive asteroid (moving right)
            // and the current asteroid is negative (moving left)
            while (!stack.empty() && stack.back() > 0 && ast < 0) {
                if (stack.back() < -ast) {
                    stack.pop_back(); // The top asteroid is smaller, so it gets destroyed
                    continue; // Check again if more collisions are possible
                } 
                else if (stack.back() == -ast) {
                    stack.pop_back(); // Both asteroids are equal in size, both explode
                }
                destroyed = true; // The current asteroid is destroyed
                break; // Stop checking further
            }

            // If the asteroid is not destroyed, add it to the stack
            if (!destroyed) {
                stack.push_back(ast);
            }
        }

        return stack; // The remaining asteroids after all collisions
    }
};
