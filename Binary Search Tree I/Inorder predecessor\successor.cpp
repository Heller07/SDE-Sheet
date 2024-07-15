//TC is O(H)
//SC IS O(1)
class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        Node* temp = root;
        while(temp != NULL){
            if(temp->key > key){
                suc = temp;
                temp = temp->left;}
            else{
                temp = temp->right;
            }
        }
        Node* temp2 = root;
        while(temp2 != NULL){
            if(temp2->key < key){
                pre = temp2;
                temp2 = temp2->right;
            }
            else{
                temp2 = temp2->left;
            }
        }
    }
};
