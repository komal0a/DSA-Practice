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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>todo;//{node,vertical,level}

        todo.push({root,{0,0}});

        while(!todo.empty()){
            TreeNode* temp=todo.front().first;
            int x= todo.front().second.first;
            int y= todo.front().second.second;
            todo.pop();

            nodes[x][y].insert(temp->val);

            if(temp->left){
                todo.push({temp->left,{x-1,y+1}});
            }
            if(temp->right){
                todo.push({temp->right,{x+1,y+1}});
            }
        }

        vector<vector<int>>ans;
        for(auto it:nodes){
            vector<int>col;
            for(auto p:it.second){
                col.insert(col.end(),p.second.begin(),p.second.end());

            }
            ans.push_back(col);
            
        }
        return ans;
    }
};