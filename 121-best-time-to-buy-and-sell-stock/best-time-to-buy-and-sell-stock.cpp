class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mini = prices[0];
        int result = 0;

        for(int i = 1; i < prices.size(); ++i) {
            if(prices[i] >= mini) {
                result = max(result, prices[i] - mini);
            }
            if(prices[i] < mini) {
                mini = prices[i];
            }
        }
        return result;
    }
};