// Time Complexity: O(N)

// serialize function: O(N), where N is the number of nodes in the tree. This is because the function performs a level-order traversal of the tree, visiting each node once.
// deserialize function: O(N), where N is the number of nodes in the tree. Similar to the serialize function, it processes each node once while reconstructing the tree.
// Space Complexity: O(N)

// serialize function: O(N), where N is the maximum number of nodes at any level in the tree. In the worst case, the queue can hold all nodes at the last level of the tree.
// deserialize function: O(N), where N is the maximum number of nodes at any level in the tree. The queue is used to store nodes during the reconstruction process, and in the worst case, it may hold all nodes at the last level.
class Codec {
public:
    // Encodes the tree into a single string
    string serialize(TreeNode* root) {
        // Check if the tree is empty
        if (!root) {
            return "";
        }

        // Initialize an empty string
        // to store the serialized data
        string s = "";
        // Use a queue for
        // level-order traversal
        queue<TreeNode*> q;
        // Start with the root node
        q.push(root);

        // Perform level-order traversal
        while (!q.empty()) {
            // Get the front node in the queue
            TreeNode* curNode = q.front();
            q.pop();

            // Check if the current node is
            // null and append "#" to the string
            if (curNode == nullptr) {
                s += "#,";
            } else {
                // Append the value of the
                // current node to the string
                s += to_string(curNode->val) + ",";
                // Push the left and right children
                // to the queue for further traversal
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }

        // Return the
        // serialized string
        return s;
    }

    // Decode the encoded
    // data to a tree
    TreeNode* deserialize(string data) {
        // Check if the
        // serialized data is empty
        if (data.empty()) {
            return nullptr;
        }

        // Use a stringstream to
        // tokenize the serialized data
        stringstream s(data);
        string str;
        // Read the root value
        // from the serialized data
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));

        // Use a queue for 
        // level-order traversal
        queue<TreeNode*> q;
        // Start with the root node
        q.push(root);

        // Perform level-order traversal
        // to reconstruct the tree
        while (!q.empty()) {
            // Get the front node in the queue
            TreeNode* node = q.front();
            q.pop();

            // Read the value of the left
            // child from the serialized data
            getline(s, str, ',');
            // If the value is not "#", create a new
            // left child and push it to the queue
            if (str != "#") {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            // Read the value of the right child
            // from the serialized data
            getline(s, str, ',');
            // If the value is not "#", create a
            // new right child and push it to the queue
            if (str != "#") {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        // Return the reconstructed
        // root of the tree
        return root;
    }
};
