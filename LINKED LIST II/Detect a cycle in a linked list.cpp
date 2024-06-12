//1
//Time Complexity: O(N * 2 * log(N) )The algorithm traverses the linked list once, performing hashmap insertions and searches in the while loop for each node. The insertion and search operations in the unordered_map have a worst-case time complexity of O(log(N)). As the loop iterates through N nodes, the total time complexity is determined by the product of the traversal (O(N)) and the average-case complexity of the hashmap operations (insert and search), resulting in O(N * 2 * log(N)). 
// Hashmaps and their time complexities are discussed in more detail here. 
// Space Complexity: O(N) The code uses a hashmap/dictionary to store encountered nodes, which can take up to O(N) additional space, where 'n' is the number of nodes in the list. Hence, the spacecomplexity is O(N) due to the use of the map to track nodes.
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> mp;
        ListNode * temp = head;
        while(temp!=NULL){
            if(mp.count(temp)){
                return true;
            }
            mp.insert(temp);
            temp = temp->next;
        }
        return false;
    }
};

//2
// Time Complexity: O(N), where N is the number of nodes in the linked list. This is because in the worst-case scenario, the fast pointer, which moves quicker, will either reach the end of the list (in case of no loop) or meet the slow pointer (in case of a loop) in a linear time relative to the length of the list.
// The key insight into why this is O(N) and not something slower is that each step of the algorithm reduces the distance between the fast and slow pointers (when they are in the loop) by one. Therefore, the maximum number of steps needed for them to meet is proportional to the number of nodes in the list.
// Space Complexity : O(1) The code uses only a constantamount of additionalspace, regardless of the linked list's length. This is achieved by using two pointers (slow and fast) to detect the loop without any significant extra memory usage, resulting in constantspace complexity, O(1).
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)return true;
        }
        return false;
    }
};
