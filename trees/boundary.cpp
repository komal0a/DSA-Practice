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
    bool leaf_node(TreeNode* node){
        return !node->left && !node->right;
    }
    void left(TreeNode* root, vector<int>&ans){
        TreeNode* cur= root->left;
        while(cur){

        if(!leaf_node(cur)){
            ans.push_back(cur->data);

        }
            if(cur->left){

            cur=cur->left;
            }else{

            cur=cur->right;
            }
        }
    }

    void leaf(TreeNode* root, vector<int>&ans){
        if(leaf_node(root)){
            ans.push_back(root->data);
            return;
        }
        if(root->left)leaf(root->left,ans);
         if(root->right)leaf(root->right,ans);
    }

     void right(TreeNode* root, vector<int>&ans){
        TreeNode* cur= root->right;
        vector<int>temp;
        while(cur){
        if(!leaf_node(cur)){
            temp.push_back(cur->data);

        }
            if(cur->right){

            cur=cur->right;
            }else{

            cur=cur->left;
            }
        
        }
        reverse(temp.begin(),temp.end());
        for(int it:temp){
        ans.push_back(it);
        }
    }

    vector <int> boundary(TreeNode* root){
    	//your code goes here
        vector<int>ans;
        if(root==nullptr)return ans;

        if(!(leaf_node(root))){
            ans.push_back(root->data);
        }
        
        left(root,ans);
        leaf(root,ans);
        right(root,ans);

        return ans;
    }
};