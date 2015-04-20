#include "leetcode.h"

/**
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

*/

class Solution {
public:
	string minWindow(string S, string T) {
		unordered_map<char, int> cnt_map;
		unordered_map<char, int> s_map;
		for (auto c : T)
		{
			if (cnt_map.find(c) == cnt_map.end())
				cnt_map[c] = 0;
			++cnt_map[c];
			s_map[c] = 0;
		}
		for (auto c : S)
		{
			if (cnt_map.find(c) == cnt_map.end())
				cnt_map[c] = 0;
			s_map[c] = 0;
		}
		int remain_count = T.size();
		string ans = "";
		int l = 0, r = 0;
		while (r < S.size())
		{
			while (r < S.size() && remain_count > 0)
			{
				s_map[S[r]]++;
				if (s_map[S[r]] <= cnt_map[S[r]])
					remain_count--;
				r++;
			}
			if (remain_count == 0)
			{
				while (remain_count == 0)
				{
					s_map[S[l]]--;
					if (s_map[S[l]] < cnt_map[S[l]] && cnt_map[S[l]] > 0)
						remain_count++;
					l++;
				}
				if (r - l + 1 < ans.length() || ans.length() == 0) ans = S.substr(l - 1, r - l + 1);
			}
		}
		return ans;
	}
};