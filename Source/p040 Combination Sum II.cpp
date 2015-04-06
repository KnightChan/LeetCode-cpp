#include "leetcode.h"

/**
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
The solution set must not contain duplicate combinations.

For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]

*/

class Solution {
public:
	vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
		vector<vector<int> > ans;
		sort(candidates.begin(), candidates.end());
		dfs(candidates, target, -1, vector<int>(), ans);
		return ans;
	}

	void dfs(vector<int> &candidates, int target, int last_index, vector<int> now_ans, vector<vector<int>> &ans)
	{
		if (target == 0)
		{
			ans.push_back(now_ans);
			return;
		}
		for (int i = last_index + 1; i < candidates.size(); i++)
			if (target >= candidates[i])
			{
			if (i > 0 && candidates[i] == candidates[i - 1])
			{
				if (i == last_index + 1 && !now_ans.empty() && now_ans.back() == candidates[i])
					; else
					continue;
			}
			now_ans.push_back(candidates[i]);
			dfs(candidates, target - candidates[i], i, now_ans, ans);
			now_ans.pop_back();
			}
	}
};
/*
int main()
{
	vector<int> v{ 1 };
	auto ans = Solution().combinationSum2(v, 1);
	displayVector2(ans);
	return 0;
}
//*/