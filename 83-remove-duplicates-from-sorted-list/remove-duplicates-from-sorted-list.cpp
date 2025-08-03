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
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == nullptr) {
            return head;
        }

        ListNode* temp = head;
        ListNode* ptr = head->next;
        int last = head->val;

        while (ptr) {
            if (ptr->val == last) {
                ListNode* deleteNode = ptr;
                ptr = ptr->next;
                if (temp && temp->next == deleteNode) {
                    temp->next = nullptr;
                }
                delete deleteNode;
            } else {
                temp->next = ptr;
                last = ptr->val;
                ptr = ptr->next;
                temp = temp->next;
            }
        }

        return head;
    }
};