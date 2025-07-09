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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* startPrev = head;
        ListNode* start = head;
        for(int i = 0; i < left - 1; ++i) {
            startPrev = start;
            start = start->next;
        }
        
        ListNode* prev = nullptr;
        ListNode* next = start;
        int step = (right - left) + 1;
        while(next && step--) {
            ListNode* nextNext = next->next;
            next->next = prev;
            prev = next;
            next = nextNext;
        }
        if(left == 1) {
            head->next = next;
            return prev;
        }
        start->next = next;
        startPrev->next = prev;
        return head;
    }
};