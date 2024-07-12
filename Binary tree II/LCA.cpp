// Time complexity: O(N) where n is the number of nodes.

// Space complexity: O(N), auxiliary space.
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root->val == p->val || root->val == q->val) return root;

        TreeNode*left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(!left && !right) return NULL;
        if(!left && right) return right;
        if(!right && left) return left;
        return root;
    }
};
