/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        // Stack to keep track of our path in the tree
        vector<TreeNode*> stack;
        
        for(int i = 0; i < s.length();) {
            // Count the dashes to get depth
            int level = 0;
            while(i < s.length() && s[i] == '-') {
                level++;
                i++;
            }
            
            // Parse the number
            int value = 0;
            while(i < s.length() && s[i] != '-') {
                value = value * 10 + (s[i] - '0');
                i++;
            }
            
            // Create new node
            TreeNode* node = new TreeNode(value);
            
            // If stack is empty, this is the root
            if(stack.empty()) {
                stack.push_back(node);
                continue;
            }
            
            // Pop from stack until we reach the parent
            while(stack.size() > level) {
                stack.pop_back();
            }
            
            // Attach node to parent
            if(!stack.back()->left) {
                stack.back()->left = node;
            } else {
                stack.back()->right = node;
            }
            
            // Add current node to stack
            stack.push_back(node);
        }
        
        return stack[0];  // Return root
    }
};