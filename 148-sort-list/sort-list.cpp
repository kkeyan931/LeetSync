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
    ListNode* getMid(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }

        ListNode* temp = new ListNode(-1);
        ListNode* newHead = temp;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        while (l1) {
            temp->next = l1;
            l1 = l1->next;
            temp = temp->next;
        }
        while (l2) {
            temp->next = l2;
            l2 = l2->next;
            temp = temp->next;
        }
        return newHead->next;
    }
    ListNode* mergeSort(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* mid = getMid(head);
        ListNode* right = mid->next;
        mid->next = nullptr;
        ListNode* l1 = mergeSort(head);
        ListNode* l2 = mergeSort(right);
        head = merge(l1, l2);
        return head;
    }
    ListNode* sortList(ListNode* head) { return mergeSort(head); }
};