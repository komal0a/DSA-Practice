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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(!root)return nullptr;

            int cur=root->val;

            if(p->val < cur && q->val < cur){
               return lowestCommonAncestor(root->left , p , q);
            } 

            else if(p->val > cur && q->val > cur){
               return lowestCommonAncestor(root->right , p , q);
            }

            return root;
    }
};