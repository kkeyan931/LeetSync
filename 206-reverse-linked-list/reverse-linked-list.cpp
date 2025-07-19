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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) {
            return head;
        }
        ListNode* prev = nullptr;
        ListNode* next = head;
        
        while(next) {
            ListNode* nextNext = next->next;
            next->next = prev;
            prev = next;
            next = nextNext;
        }
        return prev;
    }
};