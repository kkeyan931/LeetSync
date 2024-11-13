/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    bool twoRabbit(ListNode *head) {

        ListNode *slow = head;
        ListNode *fast = head;

        while (slow != NULL && fast != NULL && slow->next != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
            if(fast != NULL && fast->next != NULL) {
                fast = fast->next;
            } else {
                return false;
            }
            if(slow == fast) return true;
        }
        return false;
    }
    bool hasCycle(ListNode *head) {
        return twoRabbit(head);
    }
};