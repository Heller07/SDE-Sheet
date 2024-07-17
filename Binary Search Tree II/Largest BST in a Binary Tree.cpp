//bruute
//TC is O(n2)
class Solution {
public:
    bool isbst(TreeNode* root, int lv, int rv)
    {
        if(!root)return true;
        if(root->val<=lv || root->val>=rv)return false;

        return isbst(root->left, lv, root->val) && isbst(root->right, root->val, rv);
    }

    int findSum(TreeNode* root)
    {
        if(!root)return 0;
        if(!root->left && !root->right)return root->val;
        return root->val + findSum(root->left)+ findSum(root->right);
    }

    int find(TreeNode* root)
    {
        if(!root)return 0;
        if(!root->left && !root->right)return root->val;
        int rootbstsum=0;
        if(isbst(root, INT_MIN, INT_MAX))
        {
            rootbstsum =  findSum(root);
        }
        int leftbstsum = max(rootbstsum,find(root->left));
        int rightbstsum = max(leftbstsum, find(root->right));
        return max(0, rightbstsum);
    }
    int maxSumBST(TreeNode* root) {
        return find(root);
    }
};

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
