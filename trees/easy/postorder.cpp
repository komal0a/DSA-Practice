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
//recursive approach
     void solve(TreeNode* root, vector<int>&ans){
        if(root==nullptr)return;

       if(root->left!=NULL) solve(root->left,ans);
        if(root->right!=NULL)solve(root->right,ans);
         ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        solve(root,ans);
        return ans;
    }
};



//2 stack
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
    //  void solve(TreeNode* root, vector<int>&ans){
    //     if(root==nullptr)return;

    //    if(root->left!=NULL) solve(root->left,ans);
    //     if(root->right!=NULL)solve(root->right,ans);
    //      ans.push_back(root->val);
    // }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==nullptr)return ans;
        // solve(root,ans);
        stack<TreeNode*>st1;
        stack<int>st2;
        
        st1.push(root);
        while(!st1.empty()){
            TreeNode* node=st1.top();
            st1.pop();

            st2.push(node->val);
            if(node->left)st1.push(node->left);
            if(node->right)st1.push(node->right);
        }

        while(!st2.empty()){
            int node=st2.top();
            st2.pop();

            ans.push_back(node);
        }
        return ans;
    }
};

// 1stack
class Solution {
public:
    //  void solve(TreeNode* root, vector<int>&ans){
    //     if(root==nullptr)return;

    //    if(root->left!=NULL) solve(root->left,ans);
    //     if(root->right!=NULL)solve(root->right,ans);
    //      ans.push_back(root->val);
    // }
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    if (root == nullptr) return ans;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* node = st.top(); st.pop();
        ans.push_back(node->val);  // root is added first

        // push left before right (reverse of postorder)
        if (node->left) st.push(node->left);
        if (node->right) st.push(node->right);
    }

    reverse(ans.begin(), ans.end());  // to get postorder
    return ans;
}

};
