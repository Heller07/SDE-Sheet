//Time Complexity: O(2 * N) This is because we traverse the linked list twice: once to push the values onto the stack, and once to pop the values and compare with the linked list. Both traversals take O(2*N) ~ O(N) time.
// Space Complexity: O(N) We use a stack to store the values of the linked list, and in the worst case, the stack will have all N values,  ie. storing the complete linked list
class Solution {
public:
    bool isPalindrome(ListNode* head) {
       stack<int> st;
       ListNode* temp = head;
       while(temp!=NULL){
        st.push(temp->val);
        temp = temp->next;
       }
       temp = head;
       while(temp != NULL){
        if(temp->val != st.top()){
            return false;
        }
        st.pop();
        temp = temp->next;
       }
       return true;
    }
};
//2
// //Time Complexity: O (2* N) The algorithm traverses the linked list twice, dividing it into halves. During the first traversal, it reverses one-half of the list, and during the second traversal, it compares the elements of both halves. As each traversal covers N/2 elements, the time complexity is calculated as O(N/2 + N/2 + N/2 + N/2), which simplifies to O(2N), ultimately representing O(N). 
// Space Complexity: O(1) The approach uses a constant amount of additional space regardless of the size of the input linked list. It doesn't allocate any new data structures that depend on the input size, resulting in a space complexity of O(1).
bool isPalindrome(Node* head) {
    // Check if the linked list is empty
    // or has only one node
    if (head == NULL || head->next == NULL) {
        
         // It's a palindrome by definition
        return true; 
    }
    // Initialize two pointers, slow and fast,
    // to find the middle of the linked list
    Node* slow = head;
    Node* fast = head;
    // Traverse the linked list to find the
    // middle using slow and fast pointers
    while (fast->next != NULL && fast->next->next != NULL) {
        // Move slow pointer one step at a time
        slow = slow->next;  
        // Move fast pointer two steps at a time
        fast = fast->next->next;  
    }
    // Reverse the second half of the
    // linked list starting from the middle
    Node* newHead = reverseLinkedList(slow->next);
    // Pointer to the first half
    Node* first = head;  
     // Pointer to the reversed second half
    Node* second = newHead; 
    while (second != NULL) {
        
        // Compare data values of 
        // nodes from both halves
        // If values do not match,
        // the list is not a palindrome
        if (first->data != second->data) {  
            // Reverse the second half 
            // back to its original state
            reverseLinkedList(newHead);  
            // Not a palindrome
            return false;
        }
         // Move the first pointer
        first = first->next; 
        // Move the second pointer
        second = second->next;  
    }
    // Reverse the second half
    // back to its original state
    reverseLinkedList(newHead);  
    // The linked list is a palindrome
    return true;  
}


