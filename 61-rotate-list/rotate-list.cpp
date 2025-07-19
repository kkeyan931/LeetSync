class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    int getSize(ListNode* head) {
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        int n = getSize(head);
        k = k % n;
        if (k == 0)
            return head;

        // Step 1: Reverse the entire list
        head = reverse(head);

        // Step 2: Split at position k
        ListNode* firstPart = head;
        ListNode* curr = head;
        for (int i = 1; i < k; ++i) {
            curr = curr->next;
        }

        ListNode* secondPart = curr->next;
        curr->next = nullptr;

        // Step 3: Reverse both parts
        firstPart = reverse(firstPart);
        secondPart = reverse(secondPart);

        // Step 4: Connect both parts
        ListNode* tail = firstPart;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = secondPart;

        return firstPart;
    }
};
