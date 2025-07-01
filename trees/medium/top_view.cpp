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
    vector<int> topView(TreeNode *root){
        //your code goes here
        map<int,int>mpp;//line,val
        queue<pair<TreeNode*,int>>qt;//node,vertical line

        qt.push({root,0});

        while(!qt.empty()){
            TreeNode* node= qt.front().first;
            int line= qt.front().second;
            qt.pop();

            if(mpp.find(line)==mpp.end()){
                mpp[line]=node->data;
            }

            if(node->left)qt.push({node->left,line-1});
            if(node->right)qt.push({node->right,line+1});
        }

        vector<int>ans;
        for(auto& [line,val]:mpp){
            ans.push_back(val);
        }
        return ans;
    }
};