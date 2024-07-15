// ..Tc == O(H)
//   SC is O(1)
//we can also do by printing the inorder
int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    TreeNode<int>* temp = root;
    int ans;
    while(temp != NULL){
        if(temp->val < X){
            ans = temp->val;
            temp = temp->right;
        }
        else if(temp->val == X){
            ans = temp->val;
            break;
        }
        else{
            temp = temp->left;
        }
    }
    return ans;
}
