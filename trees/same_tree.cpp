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
    bool solve(TreeNode* p, TreeNode* q){
        if(p==nullptr && q==nullptr)return true;
        if(p==nullptr || q==nullptr)return false;
        if(p->val != q->val)return false;
            
        int lh=solve(p->left,q->left);
        int rh= solve(p->right, q->right);

        return lh && rh;

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
     return solve(p,q);
         
    }
};