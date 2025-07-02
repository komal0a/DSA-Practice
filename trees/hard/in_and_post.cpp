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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mpp;

        for(int i=0; i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }

        TreeNode* root=solve(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return root; 
    }

     TreeNode* solve(vector<int>& postorder,int poststart, int postend, vector<int>& inorder,int instart,int inend,unordered_map<int,int>&mpp){

        if(poststart>postend || instart>inend)return nullptr;

        int postroot=postorder[postend];
        int inroot=mpp[postroot];
        int size=inroot-instart;

        TreeNode* root= new TreeNode(postroot);
        root->left=solve(postorder,poststart,poststart+size-1,inorder,instart,inroot-1,mpp);
        root->right=solve(postorder,poststart+size,postend-1,inorder,inroot+1,inend,mpp);

        return root;
    }
};/**
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mpp;

        for(int i=0; i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }

        TreeNode* root=solve(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return root; 
    }

     TreeNode* solve(vector<int>& postorder,int poststart, int postend, vector<int>& inorder,int instart,int inend,unordered_map<int,int>&mpp){

        if(poststart>postend || instart>inend)return nullptr;

        int postroot=postorder[postend];
        int inroot=mpp[postroot];
        int size=inroot-instart;

        TreeNode* root= new TreeNode(postroot);
        root->left=solve(postorder,poststart,poststart+size-1,inorder,instart,inroot-1,mpp);
        root->right=solve(postorder,poststart+size,postend-1,inorder,inroot+1,inend,mpp);

        return root;
    }
};