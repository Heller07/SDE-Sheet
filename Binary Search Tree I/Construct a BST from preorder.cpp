//brute O(N2) and O(n)
class Solution {
public:
    int findindex(vector<int>& preorder, int num, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (preorder[i] > num) {
                return i;
            }
        }
        return end + 1; // Return end + 1 if no element is greater than num
    }
    TreeNode* bst(vector<int> &preorder,int start,int end){
       if (start > end) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[start]);
        int index = findindex(preorder, preorder[start], start + 1, end);
        root->left = bst(preorder,start+1,index-1);
        root->right = bst(preorder,index,end);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bst(preorder,0,preorder.size()-1);
    }
};
// TC IS O(N)
// SC IS O(H) rec stack space
class Solution {
public:
    TreeNode* builtTree(vector<int>& preorder, int &index, int &upperbound)
    {
        if(index>=preorder.size() || preorder[index]>=upperbound)
            return NULL;
        TreeNode* root=new TreeNode(preorder[index]);
        index++;
        root->left=builtTree(preorder, index, root->val);
        root->right=builtTree(preorder, index, upperbound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0, upperbound=1001;
        return builtTree(preorder, index, upperbound);
    }
};
