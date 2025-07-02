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
    void solve(TreeNode* root,vector<int>&ans){
        if(root==NULL)return;
        
        ans.push_back(root->val);
       if(root->left!=NULL) solve(root->left,ans);
        if(root->right!=NULL)solve(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
    vector<int>ans;
    solve(root,ans);
    return ans;    
    }
};


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
    
    vector<int> preorderTraversal(TreeNode* root) {
    vector<int>ans;
    if(root==nullptr)return ans;
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()){
        TreeNode* node= st.top();
        st.pop();

        ans.push_back(node->val);
        if(node->right!=nullptr)st.push(node->right);//right first then left
        // Yes, right will be processed after left — because you pushed right first and then left, and the stack is LIFO (Last-In-First-Out).


        if(node->left!=nullptr)st.push(node->left);
    }
    return ans;    
    }
};