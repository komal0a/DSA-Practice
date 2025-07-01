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
    bool solve(TreeNode* side1,TreeNode* side2){
        if(side1==nullptr && side2 == nullptr)return true;
        if(side1==nullptr || side2==nullptr)return false;

        if(side1->val !=side2->val)return false;

        int lh= solve(side1->left,side2->right);
        int rh= solve(side1->right,side2->left);

        return lh && rh;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)return true;
        return solve(root->left,root->right);

    }
};