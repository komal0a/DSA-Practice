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
    int solve(TreeNode* root){
        if(!root)return 0;

        int lh=find_l(root);
        int rh=find_r(root);

        if(lh==rh)return pow(2, lh) - 1;//i dont know how to write this
        else return 1+solve(root->left)+solve(root->right);

    }
    int find_l(TreeNode* root){
        int height=0;
        while(root){
                height++;
           root=root->left;
        }
        return height;
    }

      int find_r(TreeNode* root){
        int height=0;
        while(root){
                height++;
           root=root->right;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
     return solve(root);  
    }
};