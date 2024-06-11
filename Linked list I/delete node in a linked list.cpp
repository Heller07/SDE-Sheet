// https://leetcode.com/problems/delete-node-in-a-linked-list/description/
//1
//Time Complexity: O(1)
// Reason: It is a two-step process that can be obtained in constant time.

Space Complexity: O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
        return;
    }
};
