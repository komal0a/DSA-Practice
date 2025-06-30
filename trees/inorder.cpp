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
    // void solve(TreeNode* root, vector<int>&ans){
    //     if(root==nullptr)return;

    //    if(root->left!=NULL) solve(root->left,ans);
    //      ans.push_back(root->val);
    //     if(root->right!=NULL)solve(root->right,ans);
    // }
 vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>ans;
          
        TreeNode* node= root;
        while(true){
            if(node!=NULL){
            st.push(node);
            node=node->left;
            }else{
                if(st.empty()==true)break;
               node= st.top();
                st.pop();
                ans.push_back(node->val);
                node= node->right;
            }
        }return ans;
    }
};