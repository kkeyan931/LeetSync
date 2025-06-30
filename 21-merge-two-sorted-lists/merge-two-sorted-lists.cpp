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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        ListNode* it = new ListNode(-1);
        ListNode* newHead = it;
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;

        while (ptr1 && ptr2) {
            if (ptr1->val < ptr2->val) {
                it->next = ptr1;
                ptr1 = ptr1->next;
            } else {
                it->next = ptr2;
                ptr2 = ptr2->next;
            }
            it = it->next;
        }
        while (ptr1) {
            it->next = ptr1;
            ptr1 = ptr1->next;
            it = it->next;
        }
        while (ptr2) {
            it->next = ptr2;
            ptr2 = ptr2->next;
            it = it->next;
        }
        return newHead->next;
    }
};