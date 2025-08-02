class Solution {
public:
    int maxPathSum(TreeNode* root) {
        // Global answer initialized to the smallest possible value,
        // so it works even if all nodes are negative.
        long long ans = LLONG_MIN;
        dfs(root, ans);
        // Problem expects int; sums fit in 32-bit for typical constraints,
        // but we used long long to be safe while computing.
        return static_cast<int>(ans);
    }

private:
    // Returns the maximum "gain up" from this node to its parent:
    // the best path sum that starts at 'node' and goes up through exactly one
    // child.
    long long dfs(TreeNode* node, long long& ans) {
        if (!node)
            return 0;

        // Postorder: get gains from children first
        long long leftGain = dfs(node->left, ans);
        long long rightGain = dfs(node->right, ans);

        // Discard negative contributions
        leftGain = max(0LL, leftGain);
        rightGain = max(0LL, rightGain);

        // Path that "turns" at this node (can take both sides)
        long long bestThrough = node->val + leftGain + rightGain;

        // Update global best
        ans = max(ans, bestThrough);

        // Return the best single-branch gain to parent
        return node->val + max(leftGain, rightGain);
    }
};
