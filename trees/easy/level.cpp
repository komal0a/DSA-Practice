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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int>ds;
        vector<vector<int>>ans;
        if(root==nullptr)return ans;
        queue<TreeNode*>qt;

        qt.push(root);
        while(!qt.empty()){
            int size= qt.size();
            for(int i=0; i<size;i++){
            TreeNode* node= qt.front();
            qt.pop();

              ds.push_back(node->val);
              if(node->left)qt.push(node->left);
              if(node->right)qt.push(node->right);
            }
            ans.push_back(ds);
            ds.clear();
        }
        return ans;
    }
};