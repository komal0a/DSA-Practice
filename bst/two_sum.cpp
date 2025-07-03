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
 class BSTiterator{
    private:
    stack<TreeNode*>st;
    bool before=true;

    public:
    BSTiterator(TreeNode* root,bool isbefore){
        before=isbefore;
        pushAll(root);
    }
    bool hasnext(){
        return !st.empty();
    }

    int next(){
        TreeNode* node= st.top();
        st.pop();

        if(before)pushAll(node->left);
        else pushAll(node->right);

        return node->val;
    }

    void pushAll(TreeNode* node){
        while(node){
            st.push(node);
            if(before){
                node=node->right;
            }else{
                node=node->left;
            }
        }
    }
 };
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)return false;
        BSTiterator l(root,false);
        BSTiterator r(root,true);

         int i = l.next();
        int j = r.next();

        while (i < j) {
            int sum = i + j;
            if (sum == k) return true;
            else if(sum< k)i=l.next();
            else j=r.next();
            }

        return false;
        
    }
};