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
    int getSize(ListNode* head) {
        int count = 0;
        ListNode* ptr = head;

        while (ptr) {
            ptr = ptr->next;
            count++;
        }
        return count;
    }

    ListNode* reverse(ListNode* head, int n, int k) {
        if (n < k) {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* next = head;
        int count = k;
        while (next && count--) {
            ListNode* nextNext = next->next;
            next->next = prev;
            prev = next;
            next = nextNext;
        }

        if (next) {
            head->next = reverse(next, n - k, k);
        }

        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (k == 1) {
            return head;
        }
        int n = getSize(head);

        return reverse(head, n, k);
    }
};