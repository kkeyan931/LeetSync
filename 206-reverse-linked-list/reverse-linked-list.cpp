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
    ListNode* usingTracker(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return head;

        unordered_map<ListNode*, ListNode*> tracker;
        
        ListNode* back = head;
        ListNode* front = head->next;
        while(front != NULL) {
            tracker[front] = back;
            front = front->next;
            back = back->next;
        }
        
        ListNode* newHead = back;

        while(back != head) {
            back->next = tracker[back];
            back = tracker[back];
        }
        back->next = NULL;
        return newHead;
    }
    ListNode* reverseList(ListNode* head) {
        return usingTracker(head);
    }
};