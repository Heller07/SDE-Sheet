//1
//Time Complexity: O(N1 + N2) + O(N log N) + O(N) where N1 is the number of linked list nodes in the first list and N2 is the number of linked list nodes in the second list and N is the total number of nodes (N1+N2). Traversing both lists into the array owes O(N1 + N2), sorting the array takes O((N1+N2)*log(N1+N2)) and then traversing the sorted array and creating a list gives us another O(N1+N2).
// Space Complexity : O(N)+O(N) where N is the total number of nodes from both lists, N1 + N2. O(N) to store all the nodes of both the lists in an external array and another O(N) to create a new combined list.
Node* convertArrToLinkedList(vector<int>& arr){
    // Create a dummy node to serve
    // as the head of the linked list
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    // Iterate through the vector and
    // create nodes with vector elements
    for(int i = 0; i < arr.size(); i++){
        // Create a new node with the vector element
        temp->next = new Node(arr[i]); 
        // Move the temporary pointer
        // to the newly created node
        temp = temp->next; 
    }
    // Return the linked list starting
    // from the next of the dummy node
    return dummyNode->next; 
}

// Function to merge two sorted linked lists
Node* sortTwoLinkedLists(Node* list1, Node* list2) {
    vector<int> arr;
    Node* temp1 = list1;
    Node* temp2 = list2;

    // Storing elements of both lists into a vector
    
    // Add elements from list1 to the vector
    while(temp1 != NULL){
        arr.push_back(temp1->data); 
        // Move to the next node in list1
        temp1 = temp1->next; 
    }
    
     // Add elements from list2 to the vector
    while(temp2 != NULL){
        arr.push_back(temp2->data);
        // Move to the next node in list2
        temp2 = temp2->next; 
    }
    
    // Sorting the vector in ascending order
    sort(arr.begin(), arr.end());

    // Converting the sorted vector
    // back to a linked list
    Node* head = convertArrToLinkedList(arr); 
    
    // Return the head of the
    // merged sorted linked list
    return head; 
}

//2
//TC is linear SC is constant
class Solution {
private:
ListNode* solve(ListNode* list1, ListNode* list2) {
    if(list1->next == NULL){
        list1->next = list2;
        return list1;
    }
    ListNode* curr1 = list1;
    ListNode* next1 = curr1 -> next;
    ListNode* curr2 = list2;
    ListNode* next2 = curr2 -> next;
    while(next1 != NULL && curr2 != NULL) {
        if( (curr2 -> val >= curr1 -> val ) 
           && ( curr2 -> val <= next1 -> val)) {
            
            curr1 -> next = curr2;
            next2 = curr2->next;//keeping track of curr2-> next
            curr2 -> next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else {
            curr1 = next1;
            next1 = next1->next;
          if(next1 == NULL){
                curr1-> next = curr2;
                return list1;
            }
        }
    }
        return list1; 
}
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == NULL){
        return list2;
    }
    if(list2 == NULL){
        return list1;
    }
    if(list1 -> val <= list2 -> val ){
         return solve(list1, list2);
    }
    else
    {
       return solve(list2, list1);
    }
    }
};
