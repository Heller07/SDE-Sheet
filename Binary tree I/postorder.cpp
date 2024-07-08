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
//  */'Time Complexity: O(N) where N is the number of nodes in the binary tree as each node of the binary tree is visited exactly once.

// Space Complexity: O(N) where N is the number of nodes in the binary tree as an additional space for array is allocated to store the values of all ‘N’ nodes of the binary tree.
class Solution {
public:
void postorder(TreeNode* root, vector<int>& v) {
        if (root == NULL)
            return;
        if (root->left)
            postorder(root->left, v);
        if (root->right)
            postorder(root->right, v);
        v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        postorder(root, v);
        return v;
    }
};
