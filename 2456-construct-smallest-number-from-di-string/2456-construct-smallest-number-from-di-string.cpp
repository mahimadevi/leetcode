#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string result; // To store the final result
        stack<char> st; // Stack to handle 'D' sequences

        for (int i = 0; i <= n; i++) {
            // Push the current digit onto the stack
            st.push('1' + i);

            // If we encounter 'I' or reach the end, process the stack
            if (i == n || pattern[i] == 'I') {
                while (!st.empty()) {
                    result.push_back(st.top()); // Append the top of the stack to the result
                    st.pop(); // Pop the top element
                }
            }
        }

        return result;
    }
};