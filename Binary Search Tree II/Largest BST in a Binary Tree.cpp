//TC is O(n)
//SC is O(1)
class Info {
    public:
        int ms;
        int mini;
        int maxi;
        bool isbst;
        Info(){
            ms = 0;
            mini = INT_MAX;
            maxi = INT_MIN;
            isbst = true;
        }
};
class Solution {
public:
    int ans = 0;
    Info solve(TreeNode* root){
        if(root == NULL){
            return Info();
        }      
        Info node;
        Info nodeleft = solve(root->left);
        Info noderight = solve(root->right);
        if(nodeleft.isbst && noderight.isbst && root->val > nodeleft.maxi && root->val < noderight.mini){
            node.isbst = true;
            node.ms = root->val + nodeleft.ms + noderight.ms;
            node.mini = min(root->val,nodeleft.mini);
            node.maxi = max(root->val,noderight.maxi);
        }
        else{
            node.isbst = false;
            node.ms = max(nodeleft.ms,noderight.ms);
        }
        ans = max(ans,node.ms);
        return node;
    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
    };
