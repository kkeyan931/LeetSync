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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* temp = new ListNode(-1);
        ListNode* tempHead = temp;

        int carry = 0;
        while(l1 || l2) {
            int sum = 0;
            sum += l1 ? l1->val : 0;
            sum += l2 ? l2->val : 0;

            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;

            int num = (sum  + carry) % 10;
            carry = (sum + carry) / 10;

            temp->next = new ListNode(num);
            temp = temp->next;
        }
        if(carry) {
            temp->next = new ListNode(1);
        }
        return tempHead->next;
    }
};