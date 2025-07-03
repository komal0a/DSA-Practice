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
		vector<int> succPredBST(TreeNode* root,int key){
			vector<int> ans(2, -1);
			int suc = INT_MAX;
			int pre = INT_MIN;

			TreeNode* cur = root;
			while(cur){
				if(cur->data > key){
					suc = cur->data;
					cur = cur->left; // ✅ go left
				}
				else if(cur->data < key){
					pre = cur->data;
					cur = cur->right; // ✅ go right
				}
				else break;
			}

			if(suc != INT_MAX) ans[1] = suc;
			if(pre != INT_MIN) ans[0] = pre;

			return ans;
		}
};
