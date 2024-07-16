// Time Complexity : O(N)
// Space Complexity : O(N
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> vec;
        inorder(root, vec);
        
        // using two pointers approach for two sum
        int i  = 0, j = vec.size()-1;
        while(i<j){
            if(vec[i] + vec[j] == k)    return true;
            (vec[i] + vec[j]) < k ? i++ : j--;
        }
        return false;
    }
private:
    void inorder(TreeNode* root, vector<int>& vec){
        if(root == nullptr) return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }};

//2
// Time Complexity : O(N)
// Space Complexity : O(N)
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;
        if(myset.count(k - root->val)>0)  return true;
        myset.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
private:
    unordered_set<int> myset;
};

//3
// Time Complexity : O(N)
// Space Complexity : O(logN)
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> inord, revInord;
        TreeNode* root1 = root;
        TreeNode* root2 = root;
        
        while(true){
            while(root1)    inord.push(root1), root1 = root1->left;
            while(root2)    revInord.push(root2), root2 = root2->right;
            
            if(inord.empty() || revInord.empty())   return false;
            
            root1 = inord.top();    // node with the minimum value
            root2 = revInord.top(); // node with the maximum value.
            
            if(root1->val + root2->val == k){
                if(root1->val == root2->val)    return false;
                else    return true;
            }
            
            if(root1->val + root2->val < k){
                inord.pop();
                root1 = root1->right;
                root2 = nullptr;
            }
            
            else{
                revInord.pop();
                root2 = root2->left;
                root1 = nullptr;
            }
        }
        return false;
    }
};
//4
//https://www.youtube.com/watch?v=ssL3sHwPeb4
