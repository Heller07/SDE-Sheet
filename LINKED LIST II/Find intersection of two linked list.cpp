//1
//Time Complexity: O(m*n)
// Reason: For each node in list 2 entire lists 1 are iterated. 
// Space Complexity: O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headB != NULL) {
        ListNode* temp = headA;
        while(temp != NULL) {
            //if both nodes are same
            if(temp == headB) return headB;
            temp = temp->next;
        }
        headB = headB->next;
    }
    //intersection is not present between the lists return null
    return NULL;
    }
};
//2
// Time Complexity: O(n+m)
// Reason: Iterating through list 1 first takes O(n), then iterating through list 2 takes O(m). 
// Space Complexity: O(n)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * temp1 = headA;
        ListNode * temp2 = headB;
        unordered_set<ListNode*> mp;

        while(temp1 != NULL){
            mp.insert(temp1);
            temp1 = temp1->next;
        }
        while(temp2 != NULL){
            if(mp.count(temp2)){
                return temp2;
                break;
            }
            temp2 = temp2->next;
        }
        return NULL;
    
    }
};
//3
// Time Complexity:
// O(2max(length of list1,length of list2))+O(abs(length of list1-length of list2))+O(min(length of list1,length of list2))
// Reason: Finding the length of both lists takes max(length of list1, length of list2) because it is found simultaneously for both of them. Moving the head pointer ahead by a difference of them. The next one is for searching.
// Space Complexity: O(1)
// Reason: No extra space is used.
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * temp1 = headA;
        ListNode *temp2 = headB;
        int cnt1 = 0;
        int cnt2 = 0;
        while(temp1 != NULL){
            cnt1++;
            temp1 = temp1->next;
        }
        while(temp2 != NULL){
            cnt2++;
            temp2 = temp2->next;
        }
        int dif;
        temp1 = headA;
        temp2 = headB;
        if(cnt1>cnt2) dif = cnt1-cnt2;
        else{
           dif = cnt2-cnt1;
        }
        for(int i = 0; i<dif;i++){
            if(cnt1>cnt2) temp1 = temp1->next;
            else{
                temp2 = temp2->next;
            }
        }
        while(temp2 != NULL || temp1 != NULL){
            if(temp1 == temp2){
                return temp1;
                break;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL;
    }
};
//4
// //smaller version of //3
// Time Complexity: O(2*max(length of list1,length of list2))
// Reason: Uses the same concept of the difference of lengths of two lists.
// Space Complexity: O(1)
// Reason: No extra
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     ListNode *temp1=headA;
    ListNode *temp2=headB;

    while(temp1!=temp2){
            if (temp1 == NULL) {
                temp1 = headB;
            } else {
                temp1 = temp1->next;
            }
            if (temp2 == NULL) {
                temp2 = headA;
            } else {
                temp2 = temp2->next;
            }
        // d1 = d1 == NULL? head2:d1->next;//same as above code//condition ? value_if_true : value_if_false
        // d2 = d2 == NULL? head1:d2->next;
    }
    return temp1;
    }
};
