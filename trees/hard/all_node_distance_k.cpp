/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void find_parent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parent_node){
        queue<TreeNode*>queue;

        queue.push(root);
        while(!queue.empty()){
         
                TreeNode* node= queue.front();
                queue.pop();

                if(node->left){
                    parent_node[node->left]=node;
                    queue.push(node->left);
                }
                 if(node->right){
                    parent_node[node->right]=node;
                    queue.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent_node;
        find_parent(root,parent_node);
        unordered_map<TreeNode*,bool>vis;

        queue<pair<TreeNode*,int>>qt;
        qt.push({target,0});
        vis[target]=true;
        while(!qt.empty()){
            int size=qt.size();
             if(qt.front().second==k)break;

            for(int i=0;i<size;i++){
                TreeNode*node= qt.front().first;
                int dist=qt.front().second;

                qt.pop();

                if(node->left && !vis[node->left]){
                    qt.push({node->left,dist+1});
                    vis[node->left]=true;
                }
                if(node->right && !vis[node->right]){
                    qt.push({node->right,dist+1});
                    vis[node->right]=true;
                }
                if(parent_node[node] && !vis[parent_node[node]]){
                    qt.push({parent_node[node],dist+1});
                    vis[parent_node[node]]=true;
                }
            }

        }
        vector<int>ans;
        while(!qt.empty()){
            TreeNode*node =qt.front().first;
            qt.pop();
            ans.push_back(node->val);
        }

        return ans;
    }
};