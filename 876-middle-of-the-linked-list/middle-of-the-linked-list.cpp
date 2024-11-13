/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* iterate(ListNode* head) {
        if(head == NULL) return head;

        int count = 0;

        ListNode* it = head;
        while(it != NULL) {
            count++;
            it = it->next;
        }

        int middle = floor(count / 2);

        ListNode* result = head;

        count = 0;
        while(count<middle) {
            result = result->next;
            count++;
        }
        return result;
    }
    ListNode* middleNode(ListNode* head) {
        return iterate(head);
    }
};