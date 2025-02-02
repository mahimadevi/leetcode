class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // If concatenated strings are not equal, no common divisor exists
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        // Find the GCD of the lengths of str1 and str2
        int gcdLength = gcd(str1.size(), str2.size());
        // Return the substring of length gcdLength
        return str1.substr(0, gcdLength);
    }

private:
    // Helper function to compute GCD of two numbers
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

/* Concatenation check: "ABABAB" + "ABAB" = "ABABABABAB" and "ABAB" + "ABABAB" = "ABABABABAB. They are equal.

GCD of lengths: gcd(6, 4) = 2

Substring of length 2: "AB"

Output: "AB"
*/