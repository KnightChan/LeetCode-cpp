#include "leetcode.h"

/**
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows <= 0) return res;
        res.push_back(vector<int>(1, 1));
        while (numRows > 1)
        {
            --numRows;
            vector<int> now(1, 1), last = res.back();
            for (int i = 0;i < last.size() - 1; i++)
            {
                now.push_back(last[i] + last[i + 1]);
            }
            now.push_back(1);
            res.push_back(vector<int>(now));
        }
        return res;
    }
};
