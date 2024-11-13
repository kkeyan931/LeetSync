class Solution {
public:

    int bruteForce(vector<int>& prices) {

        int n = prices.size();
        int max = 0;
        for(int i=0;i<n;++i) {
            for(int j=i+1;j<n;++j) {
                if((prices[j] - prices[i]) > max) max = prices[j] - prices[i];
            }
        }
        return max;
    }
    int kadaneAlgo(vector<int>& prices) {
        int buy = prices[0];

        int profit = 0;

        for(int index = 1; index < prices.size(); ++index) {
            if(prices[index] < buy) {
                buy = prices[index];
            } else if((prices[index] - buy) > profit) {
                profit = prices[index] - buy;
            }
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        // return bruteForce(prices);
        return kadaneAlgo(prices);
    }
};