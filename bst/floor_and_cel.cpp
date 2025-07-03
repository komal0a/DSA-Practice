/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{	
	public:
		vector<int> floorCeilOfBST(TreeNode* root,int key){
			//your code goes here
            vector<int>ans(2,-1);
          int ceil=-1;
          int floor=-1;
            while(root){
                if(root->val==key){
                   floor=ceil=key;
                   break;
                }
            if(root->val<key){
                floor=root->val;
                root=root->right;
            }
                else{
                   ceil= root->val;
                    root=root->left;
                }
            }

            ans[0]=floor;
            ans[1]=ceil;
            return ans;
		}
};