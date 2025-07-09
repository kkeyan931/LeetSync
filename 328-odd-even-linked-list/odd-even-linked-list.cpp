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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* odd = new ListNode(-1);
        ListNode* oddHead = odd;
        ListNode* even = new ListNode(-1);
        ListNode* evenHead = even;
        
        ListNode* ptr = head;
        int count = 0;
        while(ptr) {
            if(count % 2 == 0) {
                odd->next = ptr;
                odd = odd->next;
            } else {
                even->next = ptr;
                even = even->next;
            }
            ptr = ptr->next;
            count++;
        }
        odd->next = evenHead->next;
        even->next = nullptr;
        return oddHead->next;
    }
};