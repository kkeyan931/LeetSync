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
    bool twoRabbit(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }

    bool usingMap(ListNode* head) {

        if (head == NULL)
            return false;

        unordered_map<ListNode*, bool> tracker;

        while (head != NULL) {
            if (tracker[head] == true)
                return true;
            tracker[head] = true;
            head = head->next;
        }
        return false;
    }
    bool hasCycle(ListNode* head) {
        return twoRabbit(head);
        // return usingMap(head);
    }
};