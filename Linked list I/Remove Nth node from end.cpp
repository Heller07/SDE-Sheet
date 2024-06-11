//WRITTEN BY ME solo SOLOOOOOOOOOOOOOOOOOO 0 % help
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* prev = NULL;
        ListNode* next;
        ListNode* newhead = head;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            size++;
        }
        if(size == 0 ||size == 1) return NULL;
        temp = head;
        if(size == n){//initially i  forgot this edge case
            newhead = head->next;
            delete head;
            return newhead;
        }
        int cnt = 0;
        while(temp != NULL && temp->next != NULL){
            prev = temp;
            temp = temp->next;//temp is our node to delete
            cnt++;
            
            if(cnt == size-n){
                next = temp->next;
                prev->next = next;
                break;
            }
        }
        delete temp;
        return head;
    }
};




//1
// Time Complexity: O(L)+O(L-N), We are calculating the length of the linked list and then iterating up to the (L-N)th node of the linked list, where L is the total length of the list.
// Space Complexity:  O(1), as we have not used any extra space.
Node* DeleteNthNodefromEnd(Node* head, int N) {
    if (head == NULL) {
        return NULL;
    }
    int cnt = 0;
    Node* temp = head;

    // Count the number of nodes in the linked list
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }

    // If N equals the total number of
    // nodes, delete the head
    if (cnt == N) {
        Node* newhead = head->next;
        delete (head);
        return newhead;
    }

    // Calculate the position of the node to delete (res)
    int res = cnt - N;
    temp = head;

    // Traverse to the node just before the one to delete
    while (temp != NULL) {
        res--;
        if (res == 0) {
            break;
        }
        temp = temp->next;
    }

    // Delete the Nth node from the end
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete (delNode);
    return head;
}

// //2
// //Time Complexity: O(N) since the fast pointer will traverse the entire linked list, where N is the length of the linked list.
// Space Complexity: O(1), as we have not used any extra space.
Node* DeleteNthNodefromEnd(Node* head, int N) {
    // Create two pointers, fastp and slowp
    Node* fastp = head;
    Node* slowp = head;

    // Move the fastp pointer N nodes ahead
    for (int i = 0; i < N; i++)
        fastp = fastp->next;

    // If fastp becomes NULL,
    // the Nth node from the end is the head
    if (fastp == NULL)
        return head->next;

    // Move both pointers until fastp reaches the end
    while (fastp->next != NULL) {
        fastp = fastp->next;
        slowp = slowp->next;
    }

    // Delete the Nth node from the end
    Node* delNode = slowp->next;
    slowp->next = slowp->next->next;
    delete delNode;
    return head;
}
