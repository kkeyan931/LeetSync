class Solution {
public:

    vector<int> extraArray(vector<int> &nums) {
        vector<int> neg(nums.size() / 2), pos(nums.size() / 2);

        int posCounter = 0, negCounter = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] < 0)
                neg[posCounter++] = nums[i];
            else
                pos[negCounter++] = nums[i];
        }

        posCounter = 0; negCounter = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i % 2 == 0)
            {
                nums[i] = pos[posCounter++];
            }
            else
            {
                nums[i] = neg[negCounter++];
            }
        }
        return nums;
    }

    vector<int> withPointer(vector<int> &nums) {

        vector<int> result(nums.size());

        int posIndex = 0, negIndex = 1;

        for(int i=0;i<nums.size();++i) {
            if(nums[i]>0) {
                result[posIndex] = nums[i];
                posIndex+=2;
            } else {
                result[negIndex] = nums[i];
                negIndex+=2;
            }
        }
        return result;
    }
    vector<int> rearrangeArray(vector<int>& nums) {
        return withPointer(nums);
    }
};