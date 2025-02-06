class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack; // Stack to store repeat counts
        stack<string> strStack; // Stack to store intermediate decoded strings
        string currString = ""; // This will store the current decoded string
        int num = 0; // To track the current number before '['
        
        for (char c : s) {
            if (isdigit(c)) { 
                // If the character is a digit, update the number
                num = num * 10 + (c - '0'); 
            } else if (c == '[') { 
                // When we encounter '[', push the number and current string to stacks
                numStack.push(num); 
                strStack.push(currString); 
                // Reset for next sequence inside brackets
                num = 0; 
                currString = ""; 
            } else if (c == ']') { 
                // When we encounter ']', we need to repeat the string inside
                int repeatCount = numStack.top(); 
                numStack.pop(); 
                string temp = "";
                for (int i = 0; i < repeatCount; i++) {
                    temp += currString; // Repeat the current decoded string
                }
                
                // Append it to the previous string before this bracket started
                currString = strStack.top() + temp;
                strStack.pop();
            } else { 
                // If it's a normal character, just add it to the current string
                currString += c; 
            }
        }
        
        return currString; // Return the final decoded string
    }
};
