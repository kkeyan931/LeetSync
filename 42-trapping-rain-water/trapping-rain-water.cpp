class Solution {
public:
    int sol1(vector<int> &height) {
        int n = height.size();
        vector<int> a(n);
        vector<int> b(n);

        a[0] = height[0];
        for (int i = 1; i < n; ++i) {
            a[i] = max(height[i], a[i - 1]);
        }

        b[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            b[i] = max(height[i], b[i + 1]);
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            result += max(min(a[i], b[i]) - height[i], 0);
        }
        return result;
    }
    int sol2(vector<int> &height) {
        return 0;
    }
    int trap(vector<int>& height) {
        return sol1(height);
    }
};