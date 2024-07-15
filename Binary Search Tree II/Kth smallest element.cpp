// Time Complexity: O(N) where N is the number of nodes in the Binary Search Tree as we traverse in inorder and reverse inorder fashion to get to the required nodes. We visit each node once resulting in time complexity proportional to the number of nodes in the BST.

// Space Complexity : as no additional space is allocated or data structures used to store any values.
class Solution {
public:
 void inorder(TreeNode* node, int& counter, int k, int& ans) {
        if (!node || counter >= k) return;
        inorder(node->left, counter, k, ans);
        counter++;
        if (counter == k) {
            ans = node->val;
            return;
        }
        inorder(node->right, counter, k, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        int ans;
        inorder(root,counter,k,ans);
        return ans;
    }
};
