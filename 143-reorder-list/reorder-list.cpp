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
    ListNode* reverse(ListNode *head) {
        if(head == nullptr || head->next == nullptr) {
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
    void reorderList(ListNode* head) {
        /*
            1. go to the middle
            2. split the list into two
            3. reverse the second list
            4. traverse both
        */

        if(head == nullptr || head->next == nullptr) {
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        
        while(slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* l1 = head;
        ListNode* l2 = slow->next;
        slow->next = nullptr;
        l2 = reverse(l2);

        ListNode* temp = head;
        l1 = l1->next;
        while(l1 || l2) {
            
            if(l2) {
                temp->next = l2;
                l2 = l2->next;
                temp = temp->next;
            }

            if(l1) {
                temp->next = l1;
                l1 = l1->next;
                temp = temp->next;
            }
        }
    }
};