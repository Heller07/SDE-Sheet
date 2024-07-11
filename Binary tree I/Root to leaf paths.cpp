class Solution {
  public:
    void solve(Node* root, vector<vector<int>> &ans,vector<int> &vec){
        if(root == NULL){
            return ;
        }
        vec.push_back(root->data);
        if(root-> left ==NULL && root -> right == NULL ){
            ans.push_back(vec); 
            
        }
        solve(root->left,ans,vec);
        solve(root->right,ans,vec);
        vec.pop_back();
        
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        vector<int> vec;
        solve(root,ans,vec);
        return ans;
    }
};
