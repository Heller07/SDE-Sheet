//1
// Time Complexity: O(N*M) + O(N*M log(N*M)) + O(N*M)where N is the length of the linked list along the next pointer and M is the length of the linked list along the child pointer.
// O(N*M) as we traverse through all the elements, iterating through ‘N’ nodes along the next pointer and ‘M’ nodes along the child pointer.
// O(N*M log(N*M)) as we sort the array containing N*M (total) elements.
// O(N*M) as we reconstruct the linked list from the sorted array by iterating over the N*M elements of the array.
// Space Complexity : O(N*M) + O(N*M)where N is the length of the linked list along the next pointer and M is the length of the linked list along the child pointer.
// O(N*M) for storing all the elements in an additional array for sorting.
// O(N*M) to reconstruct the linked list from the array after sorting
Node* convertArrToLinkedList(vector<int>& arr){
    // Create a dummy node to serve as
    // the head of the linked list
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    // Iterate through the vector and
    // create nodes with vector elements
    for(int i = 0; i < arr.size(); i++){
        // Create a new node
        // with the vector element
        temp->child = new Node(arr[i]); 
        // Move the temporary pointer
        // to the newly created node
        temp = temp->child; 
    }
    // Return the linked list starting
    // from the next of the dummy node
    return dummyNode->child; 
}

// Function to flatten a
// linked list with child pointers
Node* flattenLinkedList(Node* head) {
    vector<int> arr;

    // Traverse through the linked list
    while (head != nullptr) {
        // Traverse through the child
        // nodes of each head node
        Node* t2 = head;
        while (t2 != nullptr) {
            // Store each node's data in the array
            arr.push_back(t2->data);
            // Move to the next child node
            t2 = t2->child;
        }
        // Move to the next head node
        head = head->next;
    }

    // Sort the array containing
    // node values in ascending order
    sort(arr.begin(), arr.end());

    // Convert the sorted array
    // back to a linked list
    return convertArrToLinkedList(arr);
}
//2
//merge sort having child pointer
// Time Complexity: O( N*(2M) ) ~ O(2 N*M)where N is the length of the linked list along the next pointer and M is the length of the linked list along the child pointers.
// The merge operation in each recursive call takes time complexity proportional to the length of the linked lists being merged as they have to iterate over the entire lists. Since the vertical depth of the linked lists is assume to be M, the time complexity for a single merge operation is proportional to O(2*M).
// This operation operation is performed N number of times (to each and every node along the next pointer list) hence the resultant time complexity becomes: O(N* 2M).
// Space Complexity : O(1) as this algorithm uses no external space or additional data structures to store values. But a recursive stack uses O(N) space to build the recursive calls for each node along the next pointer list
Node* merge(Node* list1, Node* list2){
    // Create a dummy node as a
    // placeholder for the result
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;

    // Merge the lists based on data values
    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            res->bottom = list1;
            res = list1;
            list1 = list1->bottom;
        }
        else{
            res->bottom = list2;
            res = list2;
            list2 = list2->bottom;
        }
        res->next = NULL;
    }

    // Connect the remaining
    // elements if any
    if(list1){
        res->bottom = list1;
    } else {
        res->bottom = list2;
    }

    // Break the last node's
    // link to prevent cycles
    if(dummyNode->bottom){
        dummyNode->bottom->next = NULL;
    }

    return dummyNode->bottom;
}

Node *flatten(Node *root)
{
   // Your code here
   if(root == NULL || root->next == NULL){
        return root;
    }

    // Recursively flatten the
    // rest of the linked list
    Node* mergedHead = flatten(root->next);
    root = merge(root, mergedHead);
    return root;
}
