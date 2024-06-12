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

