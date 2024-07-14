// Time complexity: O(log n)

// Space complexity: O(log n)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        if(root->val == val) return root;
        else if(root->val > val) return searchBST(root->left,val);
        else return searchBST(root->right,val);     
}
};
// SC IS 1 TC IS SAME
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != NULL && root->val != val) {
        if (root->val > val)
            root = root->left;
        else
            root = root->right;
        }
    return root;   
}
};
