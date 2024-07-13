// Time Complexity: O(N) where N is the number of nodes in the Binary Tree. Each node of the binary node is visited exactly once. At each node, constant-time operations are performed. Hence the time complexity is O(N).

// Space Complexity : O(log2N)where N is the number of nodes in the Binary Tree. There are no additional data structures or space used but the auxiliary stack space is used during recursion. Since the recursion depth can be at most equal to the height to the Binary Tree, the space complexity is O(H) where H is the height of the Binary Tree. In the ideal case, H = log2N and in the worst case H = N (skewed tree).
class Solution {
public:
    // Initialize a global variable
    // 'prev' to keep track of the
    // previously processed node.
    TreeNode* prev = NULL;

    // Function to flatten a binary tree
    // to a right next Linked List structure
    void flatten(TreeNode* root) {
       // Base case: If the current
       // node is NULL, return.
       if(root==NULL){
           return;
       }

       // Recursive call to
       // flatten the right subtree
       flatten(root->right);
       
       // Recursive call to
       // flatten the left subtree
       flatten(root->left);
       
       // At this point, both left and right
       // subtrees are flattened, and 'prev'
       // is pointing to the rightmost node
       // in the flattened right subtree.

       // Set the right child of
       // the current node to 'prev'.
       root->right = prev;

       // Set the left child of the
       // current node to NULL.
       root->left = NULL;

       // Update 'prev' to the current
       // node for the next iteration.
       prev = root;
    }
};
// Time Complexity: O(N) where N is the number of nodes in the Binary Tree. Each node of the binary node is visited exactly once. At each node, constant-time operations are performed. Hence the time complexity is O(N).

// Space Complexity : O(log2N) where N is the number of nodes in the Binary Tree. There are no additional data structures or space used but the auxiliary stack space is used during recursion. Since the recursion depth can be at most equal to the height to the Binary Tree, the space complexity is O(H) where H is the height of the Binary Tree. In the ideal case, H = log2N and in the worst case H = N (skewed tree).
class Solution {
public:
    // Initialize a global variable
    // 'prev' to keep track of the
    // previously processed node.
    TreeNode* prev = NULL;

    // Function to flatten a binary tree
    // to a right next Linked List structure
    void flatten(TreeNode* root) {
        // Base case: If the current
        // node is NULL, return.
        if(root == NULL){
            return;
        }
        // Use a stack for
        // iterative traversal.
        stack<TreeNode*> st;
        // Push the root node
        // onto the stack.
        st.push(root);  
        
        // Continue the loop until
        // the stack is empty.
        while (!st.empty()) {  
            // Get the top node from the stack.
            TreeNode* cur = st.top(); 
            // Pop the top node.
            st.pop();  

            if (cur->right != NULL) {
                 // Push the right child
                 // onto the stack.
                st.push(cur->right); 
            }
            
            if (cur->left != NULL) {
                 // Push the left child
                 // onto the stack.
                st.push(cur->left); 
            }

            if (!st.empty()) {
                // Connect the right child to
                // the next node in the stack.
                cur->right = st.top();  
            }
            
            // Set the left child to NULL to
            // form a right-oriented linked list.
            cur->left = NULL;  
        }
    }
};

// Time Complexity: O(2N) where N is the number of nodes in the Binary Tree.

// The time complexity is linear, as each node is visited at most twice (once for establishing the temporary link and once for reverting it).
// In each step, we perform constant-time operations, such as moving to the left or right child and updating pointers.
// Space Complexity: O(1) The space complexity is constant, as the algorithm uses only a constant amount of extra space irrespective of the input size.

// Morris Traversal does not use any additional data structures like stacks or recursion, making it an in-place algorithm.
// The only space utilised is for a few auxiliary variables, such as pointers to current and in-order predecessor nodes.
class Solution {
public:
    // Function to flatten a binary tree
    // to a right next Linked List structure
    void flatten(TreeNode* root) {
        // Initialize a pointer
        // 'curr' to the root of the tree
        TreeNode* curr = root;

        // Iterate until 'curr'
        // becomes NULL
        while (curr) {
            // Check if the current
            // node has a left child
            if (curr->left) {
                // If yes, find the rightmost
                // node in the left subtree
                TreeNode* pre = curr->left;
                while (pre->right) {
                    pre = pre->right;
                }

                // Connect the rightmost node in
                // the left subtree to the current
               //  node's right child
                pre->right = curr->right;

                // Move the entire left subtree to the
                // right child of the current node
                curr->right = curr->left;

                // Set the left child of
                // the current node to NULL
                curr->left = NULL;
            }

            // Move to the next node
            // on the right side
            curr = curr->right;
        }
    }
};
