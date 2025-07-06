class Solution {
public:
    vector<int> twoPointer(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> vec(n);

        for(int i = 0; i < n; ++i) {
            vec[i] = {nums[i], i};
        }
        sort(vec.begin(), vec.end());

        int ptr1 = 0;
        int ptr2 = n - 1;

        while(ptr1 < ptr2) {
            int sum = vec[ptr1].first + vec[ptr2].first;
            if(sum == target) {
                return {vec[ptr1].second, vec[ptr2].second};
            }
            if(sum < target) {
                ptr1++;
            } else {
                ptr2--;
            }
        }
        return {};
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        return twoPointer(nums, target);
    }
};