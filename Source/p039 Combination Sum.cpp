#include "leetcode.h"

/**
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
The solution set must not contain duplicate combinations.

For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]

*/

class Solution {
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<vector<int> > ans;
		sort(candidates.begin(), candidates.end());
		dfs(candidates, target, 0, vector<int>(), ans);
		return ans;
	}

	void dfs(vector<int> &candidates, int target, int last_index, vector<int> now_ans, vector<vector<int>> &ans)
	{
		if (target == 0)
		{
			ans.push_back(now_ans);
			return;
		}
		for (int i = last_index; i < candidates.size(); i++)
			if (target >= candidates[i])
			{
			now_ans.push_back(candidates[i]);
			dfs(candidates, target - candidates[i], i, now_ans, ans);
			now_ans.pop_back();
			}
	}
};
//*
int main()
{
	vector<int> v{ 1 };
	auto ans = Solution().combinationSum(v, 1);
	displayVector2(ans);
	return 0;
}
//*/