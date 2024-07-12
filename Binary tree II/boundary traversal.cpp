// Time Complexity: O(N) where N is the number of nodes in the Binary Tree.

// Adding the left boundary of the Binary Tree results in the traversal of the left side of the tree which is proportional to the the height of the three hence O(H) ie. O(log2N). In the worst case that the tree is skewed the complexity would be O(N).
// For the bottom traversal of the Binary Tree, traversing the leaves is proportional to O(N) as preorder traversal visits every node once.
// Adding the right boundary of the Binary Tree results in the traversal of the right side of the tree which is proportional to the the height of the three hence O(H) ie. O(log2N). In the worst case that the tree is skewed the complexity would be O(N).
// Since all these operations are performed sequentially, the overall time complexity is dominated by the most expensive operation, which is O(N).
// Space Complexity: O(N) where N is the number of nodes in the Binary Tree to store the boundary nodes of the tree. O(H) or O(log2N) Recursive stack space while traversing the tree. In the worst case scenario the tree is skewed and the auxiliary recursion stack space would be stacked up to the maximum depth of the tree, resulting in an O(N) auxiliary space complexity
class Solution {
public:
    void addleft(Node *root,vector<int> &ans){
        if(root == NULL || (root->left == NULL && root->right == NULL)) return;
        ans.push_back(root->data);
        if(root->left) addleft(root->left,ans);
        else addleft(root->right,ans);
    }
    void addleaf(Node* root,vector<int> &ans){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
        }
        addleaf(root->left,ans);
        addleaf(root->right,ans);
    }
    void addright(Node*root,vector<int> &ans){
        if(root == NULL || (root->left == NULL && root->right == NULL)) return;
        if(root->right) addright(root->right,ans);
        else {addright(root->left,ans);}
        ans.push_back(root->data);
    }
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root == NULL){
          return ans;
        }
        ans.push_back(root->data);
        addleft(root->left,ans);
        addleaf(root->left,ans);
        addleaf(root->right,ans);
        addright(root->right,ans);
        return ans;
        
        
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
/
