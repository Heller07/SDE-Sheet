//1
// Time Complexity: O(N) The code traverses the entire linked list once, where 'N' is the number of nodes in the list. Therefore, the time complexity is linear, O(N).
// Space Complexity : O(N) The code uses a hash map/dictionary to store encountered nodes, which can take up to O(N) additional space, where 'n' is the number of nodes in the list. Hence, the space complexity is O(N) due to the use of the map to track nodes.
Node* detectLoop(Node* head) {
    
    // Use temp to traverse the linked list
    Node* temp = head;
    
    // hashmap to store all visited nodes
    unordered_map<Node*, int> mp;
    
    // Traverse the list using temp
    while(temp!=NULL){
        // check if temp has been encountered again
        if(mp.count(temp)!=0){
            // A loop is detected hence return temp
            return temp;
        }
        // store temp as visited
        mp[temp] = 1;
        // iterate through the list
        temp = temp->next;
    }

    // If no loop is detected, return nullptr
    return nullptr; 
}

//2
// //Time Complexity: O(N) The code traverses the entire linked list once, where 'n' is the number of nodes in the list. This traversal has a linear time complexity, O(n).
// Space Complexity : O(1) The code uses only a constant amount of additional space, regardless of the linked list's length. This is achieved by using two pointers (slow and fast) to detect the loop without any significant extra memory usage, resulting in constant space complexity, O(1).
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       ListNode * slow = head;
       ListNode * fast = head;

       while(fast != NULL && fast->next != NULL){
        slow  = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
       return fast;
        }
       } 
       return NULL;
    }
};
