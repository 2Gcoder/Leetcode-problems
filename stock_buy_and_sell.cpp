class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, j = i + 1, profit = 0,
            maxprofit = INT_MIN; // i=buy and j=sell

        if (prices.size() == 1 || (prices[i]>=prices[j] && prices.size() == 2)  )
            return 0;


        while (j < prices.size()) {
            int count = 0;
            if (prices[j] > prices[i]) // if sell > buy than only you can get profit . so this loop run 
            {
                profit = prices[j] - prices[i];
                
            }

            else { 
                i = j; // if buy->[i] > sell->[j] then at place of j we assign i to get buy of stock at min. and j wii j++; 
                j++;              
                count++;
            }
            if (count == 0)
                j++;

            if (profit > maxprofit)
                maxprofit = profit;
        }

        return maxprofit;
    }
};