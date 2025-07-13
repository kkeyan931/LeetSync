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
        ListNode* ptr = head;

        int count = 0;
        while(ptr) {
            ptr = ptr->next;
            count++;
        }
        return count;
    }
    ListNode* rec(ListNode* head, int n, int k) {
        if(n < k) {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* next = head;

        int count = k; 
        while(next && count--) {
            ListNode* nextNext = next->next;
            next->next = prev;
            prev = next;
            next = nextNext;
        }
        if(next) {
            head->next = rec(next, n - k, k);
        }
        return prev;
    } 
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = getSize(head);
        return rec(head, n, k);
    }
};