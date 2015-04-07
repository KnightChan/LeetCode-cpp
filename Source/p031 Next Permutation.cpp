#include "leetcode.h"

/**
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 ¡ú 1,3,2
3,2,1 ¡ú 1,2,3
1,1,5 ¡ú 1,5,1

*/

class Solution {
public:
	void nextPermutation(vector<int> &num) {
		int pos = num.size() - 1;
		while (pos > 0 && num[pos - 1] >= num[pos]) --pos;
		if (pos > 0)
		{
			int swap_pos = pos;
			while (swap_pos < num.size() && num[swap_pos] > num[pos - 1]) ++swap_pos;
			swap(num[pos - 1], num[swap_pos - 1]);
		}
		for (int l = pos, r = num.size() - 1; l < r; ++l, --r)
			swap(num[l], num[r]);
	}
};