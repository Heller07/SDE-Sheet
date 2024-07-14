//O(N) and O(1) O(h) is recursive stack space
class Solution {
	public:
		bool isValidBST(TreeNode* root) {

			return validate(root,-21474836473435,21474836473435);
		}

	private:
		bool validate(TreeNode* node, long lower, long upper){
			if( node == NULL ){
				// empty node or empty tree is valid always
				return true;
			}
			if( (lower < node->val) && (node->val < upper) ){
				// check if all tree nodes follow BST rule
				return validate(node->left, lower, node->val) && validate(node->right, node->val, upper);
			}
			else{
				// early reject when we find violation
				return false;
			}
		}
	};
