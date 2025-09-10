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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int findMidEle(ListNode* head, int mid) {

        ListNode* ptr = head;

        int c = 0;
        while (c != mid) {
            c++;
            ptr = ptr->next;
        }
        return ptr->val;
    }

    TreeNode* build(ListNode* head, int low, int high) {
        if (low > high)
            return nullptr;

        int mid = low + (high - low) / 2;

        int midEle = findMidEle(head, mid);

        TreeNode* root = new TreeNode(midEle);

        root->left = build(head, low, mid - 1);
        root->right = build(head, mid + 1, high);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {

        auto ptr = head;
        int c = 0;
        if (head == nullptr) {
            return nullptr;
        }

        while (ptr->next) {
            ptr = ptr->next;
            c++;
        }
        return build(head, 0, c);
    }
};