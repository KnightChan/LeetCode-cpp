#include "leetcode.h"

/**
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int min_before = INT_MAX;
        int max_profit = 0;
        for (auto x : prices)
        {
            max_profit = max(max_profit, x - min_before);
            min_before = min(min_before, x);
        }
        return max_profit;
    }
};
