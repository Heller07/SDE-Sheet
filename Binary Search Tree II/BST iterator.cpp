//TC is O(1) due to n call for n push so in 1 call n/n == 1
//SC is O(H)
class BSTIterator {
private:
    stack<TreeNode*> st;

public:
    BSTIterator(TreeNode* root) { pushallleft(root); }
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushallleft(temp->right);
        return temp->val;
    }
    bool hasNext() {
        if (st.empty())
            return false;
        return true;
    }

private:
    void pushallleft(TreeNode* root) {
        while (root != NULL) {
            st.push(root);
            root = root->left;
        }
    }
};
