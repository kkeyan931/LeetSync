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
    ListNode* rec(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* newNode = head->next;
        ListNode* repeat = newNode->next;
        newNode->next = head;

        head->next = rec(repeat);

        return newNode;
    }
    ListNode* swapPairs(ListNode* head) {
        return rec(head);
    }
};