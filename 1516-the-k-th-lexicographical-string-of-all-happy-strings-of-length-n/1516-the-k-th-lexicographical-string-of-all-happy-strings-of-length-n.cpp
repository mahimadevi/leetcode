#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        string result; // To store the k-th happy string
        int count = 0; // To count the number of happy strings generated

        // Backtracking function to generate happy strings
        function<void(string)> backtrack = [&](string current) {
            if (current.size() == n) {
                count++; // Found a happy string
                if (count == k) {
                    result = current; // Store the k-th string
                }
                return;
            }

            // Try adding 'a', 'b', or 'c' to the current string
            for (char ch : {'a', 'b', 'c'}) {
                if (current.empty() || current.back() != ch) {
                    backtrack(current + ch); // Recur with the new character
                    if (count >= k) break; // Early termination if k-th string is found
                }
            }
        };

        backtrack(""); // Start with an empty string
        return result; // Return the k-th string (or empty if not found)
    }
};
