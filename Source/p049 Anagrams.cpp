#include "leetcode.h"

/**
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.

*/

class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		unordered_map<string, vector<string>> anagrams;
		for (auto s : strs)
		{
			auto ss = s;
			sort(ss.begin(), ss.end());
			anagrams[ss].push_back(s);
		}
		vector<string> ans;
		for (auto s : anagrams)
			if (s.second.size() > 1)
				for (auto ss : s.second)
					ans.push_back(ss);
		return ans;
	}
};