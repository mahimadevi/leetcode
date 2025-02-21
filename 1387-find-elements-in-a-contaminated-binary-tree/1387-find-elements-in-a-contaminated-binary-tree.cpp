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
class FindElements {
private:
    unordered_set<int> values; // Stores all recovered values

    // Helper function to recover the tree using DFS
    void recoverTree(TreeNode* root, int val) {
        if (!root) return; // Base case: if the node is null, return

        root->val = val; // Assign the current value to the node
        values.insert(val); // Store the value in the set

        // Recover left and right children
        recoverTree(root->left, 2 * val + 1);
        recoverTree(root->right, 2 * val + 2);
    }

public:
    FindElements(TreeNode* root) {
        recoverTree(root, 0); // Start recovering the tree from the root with value 0
    }

    bool find(int target) {
        return values.count(target); // Check if the target exists in the set
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

