//1*/O(n2)
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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = maxDepth(root->left) + maxDepth(root->right);
        int ans = max(op1, max(op2, op3));
        return ans;
    }
};
// Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each node exactly once during the postorder traversal.

// Space Complexity : O(1) as no additional space or data structures is created that is proportional to the input size of the tree. O(H) Recursive Stack Auxiliary Space : The recursion stack space is determined by the maximum depth of the recursion, which is the height of the binary tree denoted as H. In the balanced case it is log2N and in the worst case its N.
class Solution {
public:
    // Function to find the
    // diameter of a binary tree
    int diameterOfBinaryTree(Node* root) {
        // Initialize the variable to
        // store the diameter of the tree
        int diameter = 0;
        // Call the height function to traverse
        // the tree and calculate diameter
        height(root, diameter);
        // Return the calculated diameter
        return diameter;
    }

private:
    // Function to calculate the height of
    // the tree and update the diameter
    int height(Node* node, int& diameter) {
        // Base case: If the node is null,
        // return 0 indicating the
        // height of an empty tree
        if (!node) {
            return 0;
        }

        // Recursively calculate the
        // height of left and right subtrees
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        // Update the diameter with the maximum
        // of current diameter or sum of
        // left and right heights
        diameter = max(diameter, lh + rh);

        // Return the height of
        // the current node's subtree
        return 1 + max(lh, rh);
    }
};
