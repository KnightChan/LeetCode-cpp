#include "leetcode.h"

/**
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        for (int x : nums)
            us.insert(x);
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (us.count(nums[i] - 1)) continue;
            int cnt = 1;
            while (us.count(nums[i] + cnt)) ++cnt;
            ans = max(ans, cnt);
        }
        return ans;
    }
};
