class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int n=nums.size();

        vector<vector<int>> result;
        
        for(int ptr1=0;ptr1<n-2 && nums[ptr1]<=0;ptr1++){
            
            if(ptr1==0 || nums[ptr1]!=nums[ptr1-1]){
            
                int ptr2=ptr1+1;
                int ptr3=n-1;
            
                while(ptr2<ptr3){
                
                    int sum = nums[ptr1] + nums[ptr2] + nums[ptr3];
    
                    if(sum==0){
                
                        result.push_back({nums[ptr1],
                                        nums[ptr2],nums[ptr3]});
                        ptr2++;
                        ptr3--;
                        
                        while(ptr2<ptr3 && nums[ptr2]==nums[ptr2-1]){
                            ptr2++;
                        }
                    }
                    else if(sum > 0){
                        ptr3--;
                    }
                
                    else{
                        ptr2++;
                    }
                }
            }
        }
        
        return result;
        
    }
};