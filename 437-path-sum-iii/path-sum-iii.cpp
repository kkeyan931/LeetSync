class Solution {
public:
    void rec(TreeNode* root, int& count, unordered_map<long long, int>& umap, long long sum, int k) {
        if (root == nullptr) return;

        sum += root->val;

        // ✅ This line handles everything, including sum == k
        count += umap[sum - k];

        umap[sum]++;

        rec(root->left, count, umap, sum, k);
        rec(root->right, count, umap, sum, k);

        umap[sum]--; // backtrack
    }

    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        unordered_map<long long, int> umap;
        umap[0] = 1; // base case to handle sum == target from root
        rec(root, count, umap, 0, targetSum);
        return count;
    }
};
