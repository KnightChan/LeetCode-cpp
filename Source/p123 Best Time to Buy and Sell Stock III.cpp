#include "leetcode.h"

/**
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        vector<int> profits(prices.size(), 0);
        vector<int> reverseProfits(prices.size() + 1, 0);
        for (int i = 1, minPrice = prices.size() > 0?prices[0]:0; i < prices.size(); i++)
        {
            profits[i] = max(profits[i - 1], prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        for (int i = prices.size() - 1, maxPrice = prices.size() > 0?prices[prices.size() - 1]:0; i >= 0; i--)
        {
            reverseProfits[i] = max(reverseProfits[i + 1], maxPrice - prices[i]);
            maxPrice = max(maxPrice, prices[i]);
        }
        int ans = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            ans = max(ans, profits[i] + reverseProfits[i + 1]);
        }
        return ans;
    }
};
