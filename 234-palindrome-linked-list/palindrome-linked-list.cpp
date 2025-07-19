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
    int getSize(ListNode *head) {
        int count = 0;
        ListNode* ptr = head;

        while(ptr) {
            ptr = ptr->next;
            count++;
        }
        return count;
    }
    ListNode* reverse(ListNode *head){

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
    bool isPal(ListNode *list1, ListNode *list2) {

        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;

        while(ptr1 && ptr2) {
            if(ptr1->val != ptr2->val) {
                return false;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        
        int half = (getSize(head) + 1) / 2;

        ListNode* ptr = head;
        for(int i = 1; i < half; ++i) {
            ptr = ptr->next;
        }

        ListNode* list1 = head;
        ListNode* list2 = ptr->next;

        list2 = reverse(list2);

        ptr->next = nullptr;

        return isPal(list1, list2);
    }
};