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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr)return ans;
        vector<int>ds;
        queue<TreeNode*>qt;

        bool flag=false;
        qt.push(root);  
        while(!qt.empty()){
            int size= qt.size();
            for(int i=0; i<size ;i++){
             TreeNode* node=qt.front();
            qt.pop();

            ds.push_back(node->val);
            if(node->left)qt.push(node->left);
            if(node->right)qt.push(node->right);
            }
            if(flag)reverse(ds.begin(),ds.end());
            ans.push_back(ds);
            ds.clear();
            flag=!flag;
        }  

        return ans;
    }
};