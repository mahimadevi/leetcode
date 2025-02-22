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
    TreeNode* recoverFromPreorder(string_view s) {
        vector<TreeNode*> path;
        size_t pos = 0;
        
        while (pos < s.length()) {
            // Get level and value together
            size_t level = 0;
            int val = 0;
            
            // Count level (dashes)
            while (pos < s.length() && s[pos] == '-') {
                level++;
                pos++;
            }
            
            // Get value
            while (pos < s.length() && s[pos] != '-') {
                val = val * 10 + (s[pos] - '0');
                pos++;
            }
            
            // Resize path to correct level
            while (path.size() > level) {
                path.pop_back();
            }
            
            // Create and link new node
            TreeNode* node = new TreeNode(val);
            if (!path.empty()) {
                if (!path.back()->left) {
                    path.back()->left = node;
                } else {
                    path.back()->right = node;
                }
            }
            
            path.push_back(node);
        }
        
        return path[0];
    }
};