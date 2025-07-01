/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
	public:
        void solve(TreeNode* root, vector<vector<int>>&ans,vector<int>&ds){
            if(root==nullptr)return;

            ds.push_back(root->data);

            if(root->left==nullptr && root->right==nullptr){
            ans.push_back(ds);
            }

           solve(root->left,ans,ds);
            solve(root->right,ans,ds);

            ds.pop_back();
        }

		vector<vector<int>> allRootToLeaf(TreeNode* root) {
            //your code goes here
            vector<vector<int>>ans;
            vector<int>ds;
            solve(root,ans,ds);
            return ans;
		}
};