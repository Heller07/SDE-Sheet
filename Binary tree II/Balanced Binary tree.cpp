// Time Complexity: O(N2) where N is the number of nodes in the Binary Tree.This arises as we calculate the height of each node and to calculate the height for each node, we traverse the tree which is proportional to the number of nodes. Since this calculation is performed for each node in the tree, the complexity becomes: O(N x N) ~ O(N2).

// Space Complexity : O(1) as no additional data structures or memory is allocated.O(H): Recursive Stack Space is used to calculate the height of the tree at each node which is proportional to the height of the tree.The recursive nature of the getHeight function, which incurs space on the call stack for each recursive call until it reaches the leaf nodes or the height of the tree.
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int l1 = maxDepth(root->left);
        int r1 = maxDepth(root->right);
        int ans = max(l1, r1) + 1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        bool cond = abs(maxDepth(root->left) - maxDepth(root->right)) <= 1;
        if (left && right && cond)
            return true;
        else
            return false;
    }
};
//TC AND SC IS O(N)
class Solution {
public:
    bool isBalanced(TreeNode* root) { return dfsHeight(root) != -1; }

    int dfsHeight(TreeNode* root) {

        if (root == NULL)
            return 0;

        int leftHeight = dfsHeight(root->left);

        int rightHeight = dfsHeight(root->right);
        if (leftHeight == -1 || rightHeight == -1)
            return -1;

        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        return max(leftHeight, rightHeight) + 1;
    }
};
