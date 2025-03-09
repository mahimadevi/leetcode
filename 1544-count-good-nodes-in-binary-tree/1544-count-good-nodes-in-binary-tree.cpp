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
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val); // Start DFS with the root's value as the initial maximum
    }

private:
    int dfs(TreeNode* node, int maxSoFar) {
        if (node == nullptr) {
            return 0; // Base case: no nodes to process
        }

        int count = 0; // Initialize count for the current node

        // If the current node's value is greater than or equal to the maximum so far, it's a good node
        if (node->val >= maxSoFar) {
            count++;
            maxSoFar = node->val; // Update the maximum value
        }

        // Recursively count good nodes in the left and right subtrees
        count += dfs(node->left, maxSoFar);
        count += dfs(node->right, maxSoFar);

        return count;
    }
};