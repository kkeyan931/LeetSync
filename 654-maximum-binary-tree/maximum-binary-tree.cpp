/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findMaxIndex(vector<int> &nums, int i, int j) {
        
        int maxi = nums[i];
        int maxIndex = i;
        for(int k = i; k <= j; ++k) {
            if(nums[k] > maxi) {
                maxi = nums[k];
                maxIndex = k;
            }
        }
        return maxIndex;
    }
    TreeNode* rec(vector<int> &nums, int i, int j) {
        if(i > j) {
            return nullptr;
        }
        int index = findMaxIndex(nums, i, j);
        
        TreeNode* root = new TreeNode(nums[index]);

        root->left = rec(nums, i, index - 1);
        root->right = rec(nums, index + 1, j);

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return rec(nums, 0, nums.size() - 1);
    }
};