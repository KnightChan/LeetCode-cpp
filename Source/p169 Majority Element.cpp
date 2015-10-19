#include "leetcode.h"

/**
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

 */
 
 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (!nums.size()) return 0;
        int ans = nums[0];
        for (int count = 1, i = 1; i < nums.size(); i++)
        {
            if (nums[i] == ans)
                ++count;
            else --count;
            if (!count) 
            {
                ans = nums[i];
                count = 1;
            }
        }
        return ans;
    }
};
