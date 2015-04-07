#include "leetcode.h"

/**
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].

*/

class Solution {
public:
	vector<vector<int> > permuteUnique(vector<int> &num) {
		sort(num.begin(), num.end());
		vector<vector<int> > ans{ num };
		while (next_permutation(num.begin(), num.end()))
			ans.push_back(num);
		return ans;
	}
};