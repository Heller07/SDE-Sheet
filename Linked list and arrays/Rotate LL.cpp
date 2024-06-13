// Time Complexity: O(Number of nodes present in the list*k)
// Reason: For k times, we are iterating through the entire list to get the last element and move it to first.
// Space Complexity: O(1)
node* rotateRight(node* head,int k) {
    if(head == NULL||head->next == NULL) return head;
    for(int i=0;i<k;i++) {
        node* temp = head;
        while(temp->next->next != NULL) temp = temp->next;
        node* end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }
    return head;
}




// Time Complexity: O(length of list) + O(length of list - (length of list%k))
// Reason: O(length of the list) for calculating the length of the list. O(length of the list - (length of list%k)) for breaking link.
// Space Complexity: O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* temp = head;
        int len=0;
         while(temp){
             temp = temp->next;
             len++;
         }
           k = k%len; //k times rotate kro ya k%len times order will same
        
        while(k>0){

            temp  = head ;
            while(temp->next->next != NULL){
            temp = temp->next;  
        }
            ListNode* end = temp->next;
            temp->next = NULL;
            end->next = head;
            head = end;
            k--;
        }
        return head;
    }};

