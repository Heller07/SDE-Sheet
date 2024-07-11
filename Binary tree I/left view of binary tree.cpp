// Time Complexity: O(N) where N is the number of nodes in the binary tree. Each node of the binary tree is enqueued and dequeued exactly once, hence all nodes need to be processed and visited. Processing each node takes constant time operations which contributes to the overall linear time complexity.

// Space Complexity : O(N) where N is the number of nodes in the binary tree. In the worst case, the queue has to hold all the nodes of the last level of the binary tree, the last level could at most hold N/2 nodes hence the space complexity of the queue is proportional to O(N). The resultant vector answer also stores the values of the nodes level by level and hence contains all the nodes of the tree contributing to O(N) space as well.
class Solution {
public:
    // Function to return the
    // Right view of the binary tree
    vector<int> rightsideView(Node* root) {
        // Vector to store
        // the result
        vector<int> res;

        // Get the level order
        // traversal of the tree
        vector<vector<int>> levelTraversal = levelOrder(root);

        // Iterate through each level and
        // add the last element to the result
        for (auto level : levelTraversal) {
            res.push_back(level.back());
        }

        return res;
    }

    // Function to return the
    // Left view of the binary tree
    vector<int> leftsideView(Node* root) {
        // Vector to store the result
        vector<int> res;

        // Get the level order
        // traversal of the tree
        vector<vector<int>> levelTraversal = levelOrder(root);

        // Iterate through each level and
        // add the first element to the result
        for (auto level : levelTraversal) {
            res.push_back(level.front());
        }

        return res;
    }

private:
    // Function that returns the
    // level order traversal of a Binary tree 
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;

        // Return an empty vector
        // if the tree is empty
        if (!root) {
            return ans;
        }

        // Use a queue to perform
        // level order traversal
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            // Process each node
            // in the current level
            for (int i = 0; i < size; i++) {
                Node* top = q.front();
                level.push_back(top->data);
                q.pop();

                // Enqueue the left
                // child if it exists
                if (top->left != NULL) {
                    q.push(top->left);
                }

                // Enqueue the right
                // child if it exists
                if (top->right != NULL) {
                    q.push(top->right);
                }
            }

            // Add the current
            // level to the result
            ans.push_back(level);
        }

        return ans;
    }
};

// Time Complexity: O(log2N) where N is the number of nodes in the Binary Tree. This complexity arises as we travel along the height of the Binary Tree. For a balanced binary tree, the height is log2N but in the worst case when the tree is skewed, the complexity becomes O(N).

// Space Complexity : O(log2N) where N is the number of nodes in the Binary Tree. This complexity arises because we store the leftmost and rightmost nodes in an additional vector. The size of this result vector is proportional to the height of the Binary Tree which will be log2N when the tree is balanced and O(N) in the worst case of a skewed tree.

// O(H): Recursive Stack Space is used to calculate the height of the tree at each node which is proportional to the height of the tree.
// The recursive nature of the getHeight function, which incurs space on the call stack for each recursive call until it reaches the leaf nodes or the height of the tree.
class Solution {
public:
    // Function to return the Right view of the binary tree
    vector<int> rightsideView(Node* root){
        // Vector to store the result
        vector<int> res;
        
        // Call the recursive function
        // to populate the right-side view
        recursionRight(root, 0, res);
        
        return res;
    }
    
    // Function to return the Left view of the binary tree
    vector<int> leftsideView(Node* root){
        // Vector to store the result
        vector<int> res;
        
        // Call the recursive function
        // to populate the left-side view
        recursionLeft(root, 0, res);
        
        return res;
    }

private:
    // Recursive function to traverse the
    // binary tree and populate the left-side view
    void recursionLeft(Node* root, int level, vector<int>& res){
        // Check if the current node is NULL
        if(root == NULL){
            return;
        }
        
        // Check if the size of the result vector
        // is equal to the current level
        if(res.size() == level){
            // If equal, add the value of the
            // current node to the result vector
            res.push_back(root->data);
        }
        
        // Recursively call the function for the
        // left child with an increased level
        recursionLeft(root->left, level + 1, res);
        
        // Recursively call the function for the
        // right child with an increased level
        recursionLeft(root->right, level + 1, res);
    }
    
    // Recursive function to traverse the
    // binary tree and populate the right-side view
    void recursionRight(Node* root, int level, vector<int> &res){
        // Check if the current node is NULL
        if(root == NULL){
            return;
        }
        
        // Check if the size of the result vector
        // is equal to the current level
        if(res.size() == level){
            // If equal, add the value of the
            // current node to the result vector
            res.push_back(root->data);
            
            // Recursively call the function for the
            // right child with an increased level
            recursionRight(root->right, level + 1, res);
            
            // Recursively call the function for the
            // left child with an increased level
            recursionRight(root->left, level + 1, res);
        }
    }
};
