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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        vector<int> leaves2;
        
        // Collect leaf nodes for the first tree
        collectLeaves(root1, leaves1);
        
        // Collect leaf nodes for the second tree
        collectLeaves(root2, leaves2);
        
        // Compare the two sequences
        return leaves1 == leaves2;
    }
    
private:
    void collectLeaves(TreeNode* node, vector<int>& leaves) {
        if (node == nullptr) {
            return;
        }
        
        // If it's a leaf node, add its value to the list
        if (node->left == nullptr && node->right == nullptr) {
            leaves.push_back(node->val);
        }
        
        // Recursively collect leaves from the left and right subtrees
        collectLeaves(node->left, leaves);
        collectLeaves(node->right, leaves);
    }
};