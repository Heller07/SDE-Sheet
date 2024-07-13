// Time Complexity: O(N) where N is the number of nodes in the binary tree. This is because the algorithm traverses each node exactly once, performing constant-time operations at each node.

// Space Complexity: O(N) where N is the number of nodes in the Binary Tree.

// In the worst case scenario the tree is skewed and the auxiliary recursion stack space would be stacked up to the maximum height of the tree, resulting in a space complexity of O(N).
// In the optimal case of a balanced tree, the auxiliary space would take up space proportional to O(log2N).
class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    bool sum(Node* root){
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        int lef = 0;
        int rig = 0;
        if(root->left) lef = root->left->data;
        if(root->right)rig = root->right->data;
        bool left = sum(root->left);
        bool right = sum(root->right);
        if(left && right && (root->data == (lef+rig))) return true;
        return false;
    }
    
    int isSumProperty(Node *root)
    {
     // Add your code here
            if(root==NULL) return 1;
          if(sum(root)==true) return 1;
          return 0;
    }
};

//TC AND SC ARE SAME
// BINARY TREE INTO CHILDREN SUM TREE
class Solution {
public:
    // Function to change the values of the nodes
    // based on the sum of its children's values.
    void changeTree(TreeNode* root) {
        // Base case: If the current node
        // is NULL, return and do nothing.
        if (root == NULL) {
            return;
        }

        // Calculate the sum of the values of
        // the left and right children, if they exist.
        int child = 0;
        if (root->left) {
            child += root->left->val;
        }
        if (root->right) {
            child += root->right->val;
        }

        // Compare the sum of children with
        // the current node's value and update
        if (child >= root->val) {
            root->val = child;
        } else {
            // If the sum is smaller, update the
            // child with the current node's value.
            if (root->left) {
                root->left->val = root->val;
            } else if (root->right) {
                root->right->val = root->val;
            }
        }

        // Recursively call the function
        // on the left and right children.
        changeTree(root->left);
        changeTree(root->right);

        // Calculate the total sum of the
        // values of the left and right
        // children, if they exist.
        int tot = 0;
        if (root->left) {
            tot += root->left->val;
        }
        if (root->right) {
            tot += root->right->val;
        }

        // If either left or right child
        // exists, update the current node's
        // value with the total sum.
        if (root->left or root->right) {
            root->val = tot;
        }
    }
};
