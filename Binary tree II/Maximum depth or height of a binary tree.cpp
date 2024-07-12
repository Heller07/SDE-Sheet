// Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each node exactly once during the traversal to determine the maximum depth.

// Space Complexity: O(N) where N is the number of nodes in the Binary Tree because in the worst case scenario the tree is balanced and has N/2 nodes in its last level which will have to be stored in the queue.
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
       
        int l1 = maxDepth(root->left);
        int r1 = maxDepth(root->right);
        int ans = max(l1,r1)+1;
        return ans;
    }
};
