// TC AND SC ARE O(N) AND O(1) but due to recursive stack space we can say O(n) in worst case
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;

        if(root->left) root->left->next = root->right;
        if(root->right && root->next != NULL) root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
        return root;
    }
};
//in iterative SC is O(1)
if(root == NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size(); // get size of queue 
            for(int i=0 ; i < size ; i++){
                Node* item = q.front(); 
                if(size - 1 == i) // checking the last value of the level
                     item -> next = NULL; 
                
                q.pop();
                
                if(size - 1 != i) // if this is not the last value then previous value will point to next one
                     item -> next = q.front(); 
                
                if(item -> left != NULL)
                    q.push(item -> left);
                if(item -> right != NULL)
                    q.push(item -> right);
            }
        } 
        return root; 
