//same as kth smallest O(n) and O(1)
class Solution
{
    public:
    void inorder(Node* node, int& counter, int K, int& ans) {
        if (!node || counter >= K) return;
        inorder(node->right, counter, K, ans);
        counter++;
        if (counter == K) {
            ans = node->data;
            return;
        }
        inorder(node->left, counter, K, ans);
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        int counter = 0;
        int ans;
        inorder(root,counter,K,ans);
        return ans;
    }
};
