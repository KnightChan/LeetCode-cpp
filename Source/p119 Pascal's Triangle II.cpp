#include "leetcode.h"

/**
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        while (rowIndex >= 0)
        {
            --rowIndex;
            res.push_back(1);
            for (int i = res.size() - 2; i > 0; --i)
            {
                res[i] += res[i-1];
            }
        }
        return res;
    }
};
