/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        // if(root==nullptr)return null;

        if(root==nullptr|| root==p || root==q)return root;

        TreeNode* lh=solve(root->left,p,q);
         TreeNode* rh=solve(root->right,p,q);

        if(lh==nullptr){
            return rh;
        }else if(rh==nullptr){
            return lh;
        }else{
            return root;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       return solve(root,p,q);
    }
};