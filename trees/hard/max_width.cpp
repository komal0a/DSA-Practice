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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr)return 0;

        queue<pair<TreeNode*,int>>qt;//node,i;

        qt.push({root,0});
        int maxi=0;
        while(!qt.empty()){
            int size=qt.size();
            unsigned long long mini=qt.front().second;
            unsigned long long first=0,last=0;
            for(int i=0; i<size;i++){
                TreeNode* node= qt.front().first;
                 unsigned long long val= qt.front().second-mini;
                qt.pop();
                
                if(i==0)first=val;
                if(i==size-1)last=val;


              if(node->left)  qt.push({node->left,val*2+1});
               if(node->right) qt.push({node->right,val*2+2});
              }
                maxi=max(maxi,static_cast<int>(last-first+1));
                 }
        return maxi;
    }
};