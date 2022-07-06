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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size() != preorder.size())
            return NULL;
        map<int,int>h;
        for(int i=0;i<inorder.size();i++){
            h[inorder[i]]=i;
        }
        return buildPreIn(inorder, 0, inorder.size()-1, preorder, 0, preorder.size()-1, h);
    }
    TreeNode* buildPreIn(vector<int> &inorder, int is, int ie, vector<int> &preorder, int ps, int pe, map<int,int> &h){
        if(ps>pe || is>ie)
            return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);
        int inRoot = h[preorder[ps]];
        int numsLeft = inRoot - is;
        
        root->left = buildPreIn(inorder, is, inRoot-1, preorder, ps+1, ps+numsLeft, h);
        root->right = buildPreIn(inorder, inRoot+1, ie, preorder, ps+numsLeft+1, pe, h);
        
        return root;
    }
};