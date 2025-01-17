class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();

        if(n==1) return nums;
        vector<int> result;

        int el1, el2, count1=0, count2=0;
        for(int i=0;i<n;++i) {
            if(count1==0 && el2!=nums[i]) {
                el1 = nums[i];
            } else if(count2==0 && el1!=nums[i]) {
                el2 = nums[i];
            }
            if(nums[i]==el1) count1++;
            else if(nums[i]==el2) count2++;
            else {
                count1--; count2--;
            }
        }

        int majorityCount = n/3;

        count1 = 0, count2 = 0; 
        for(int i=0;i<n;++i) {
            if(nums[i]==el1) count1++;
            else if(nums[i]==el2) count2++;
        }
        if(count1>n/3 && count2>n/3) return {el1, el2};
        if(count1>n/3) return {el1};
        if(count2>n/3) return {el2};
        return {};
    }
};