class Solution {
public:
    int sol1(vector<int>& height) {
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
    int sol2(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;

        int result = 0;

        int left_max = 0;
        int right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                height[left] >= left_max ? (left_max = height[left])
                                         : result += (left_max - height[left]);
                left++;
            } else {
                height[right] >= right_max ? (right_max = height[right])
                                           : result += (right_max - height[right]);
                right--;
            }
        }
        return result;
    }
    int trap(vector<int>& height) { 
        // return sol1(height); 
        return sol2(height);
    }
};