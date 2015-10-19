#include "leetcode.h"

/**
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note: 
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?


*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> dq;
        vector<int> topk;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!dq.empty() && dq.front().first <= i - k) dq.pop_front();
            while (!dq.empty() && dq.back().second <= nums[i]) dq.pop_back();
            dq.push_back(make_pair(i, nums[i]));
            if (i >= k - 1) 
                topk.push_back(dq.front().second);
        }
        return topk;
    }
};
