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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) {
            return l2;
        }
        if(l2 == nullptr) {
            return l1;
        }
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;

        ListNode* temp = new ListNode(-1);
        ListNode* tempHead = temp;

        while(ptr1 && ptr2) {
            if(ptr1->val < ptr2->val) {
                temp->next = ptr1;
                ptr1 = ptr1->next;
            } else {
                temp->next = ptr2;
                ptr2 = ptr2->next;
            }
            temp = temp->next;
        }
        if(ptr1) {
            temp->next = ptr1;
        }
        if(ptr2) {
            temp->next = ptr2;
        }
        return tempHead->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int amount = lists.size();
        int interval = 1;
        while (interval < amount) {
            for (int i = 0; i < amount - interval; i += interval * 2)
                lists[i] = merge(lists[i], lists[i + interval]);
            interval *= 2;
        }
        return amount > 0 ? lists[0] : NULL;
    }
};