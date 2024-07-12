// Time Complexity: O(N+M) where N is the number of nodes in the first Binary Tree and M is the number of nodes in the second Binary Tree. This complexity arises from visiting each node of the two binary nodes during their comparison.

// Space Complexity: O(1) as no additional space or data structures is created that is proportional to the input size of the tree. O(H) Recursive Stack Auxiliary Space : The recursion stack space is determined by the maximum depth of the recursion, which is the height of the binary tree denoted as H. In the balanced case it is log2N and in the worst case (its N).
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q== NULL) return true;
        if( p == NULL || q ==NULL){
            return false;
        }
        bool left = isSameTree(p->left,q->left);
        bool right = isSameTree(p->right,q->right);
        bool cond = p->val == q->val;
        if(left && right && cond) return true;
        return false;
        
    }
};
