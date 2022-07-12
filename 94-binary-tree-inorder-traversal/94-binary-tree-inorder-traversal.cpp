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
/*RECURSSION
class Solution {
public:
    void in(TreeNode* root, vector<int> &v){
        if(root==NULL){
            return;
        }
        else{
            in(root->left,v);
            v.push_back(root->val);
            in(root->right,v);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        in(root,v);
        return v;
    }
    
};
ITERATION
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        TreeNode* node = root;
        vector<int>v;
        while(true){
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }
            else {
                if(st.empty()==true) break;
                node=st.top();
                st.pop();
                v.push_back(node->val);
                node=node->right;
            }
        }
        return v;
    }
    
};
*/



/*Morriss traversal*/
class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int>res;
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left == NULL){
                res.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right == NULL){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    res.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return res;
    }
};