class Solution {
public:
    vector<int> postorder(TreeNode* root) {
        vector<int> pre, ino, post;
        if (root == nullptr) return post;

        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});

        while (!st.empty()) {
            auto &p = st.top();
            TreeNode* node = p.first;
            int &num = p.second;

            if (num == 1) {
                pre.push_back(node->data);
                num++;
                if (node->left) st.push({node->left, 1});
            }
            else if (num == 2) {
                ino.push_back(node->data);
                num++;
                if (node->right) st.push({node->right, 1});
            }
            else {
                post.push_back(node->data);
                st.pop();
            }
        }

        return post;  // only postorder returned as per function
    }
};
