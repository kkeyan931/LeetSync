class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int,int> umap;
        stack<int> stack;
        for(int i = nums2.size() - 1; i >= 0; --i) {
            while(!stack.empty() && nums2[stack.top()] <= nums2[i]) {
                stack.pop();
            }
            if(stack.empty()) {
                umap[nums2[i]] = -1;
            } else {
                umap[nums2[i]] = nums2[stack.top()];
            }
            stack.push(i);
        }

        vector<int> result;

        for(auto num : nums1) {
            result.push_back(umap[num]);
        }

        return result;
    }
};