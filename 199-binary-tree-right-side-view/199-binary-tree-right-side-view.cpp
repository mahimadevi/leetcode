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
    void right(TreeNode*root, vector<int> &v, int level){
        TreeNode*node=root;
        if(node==NULL)
            return;
        if(level==v.size())
            v.push_back(node->val);
        
        right(node->right,v,level+1);
        right(node->left,v,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        right(root,v,0);
        return v; 
    }
};