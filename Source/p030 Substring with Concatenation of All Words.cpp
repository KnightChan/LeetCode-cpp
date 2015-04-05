#include "leetcode.h"

/**
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

class Solution {
public:
	vector<int> findSubstring(string S, vector<string> &L) {
		int word_len = L[0].length();
		unordered_map<string, int> word_map;
		for (auto s : L)
			++word_map[s];
		vector<int> ans;
		
		for (int i = 0; i < word_len; i++)
		{
			int now_count = 0;
			unordered_map<string, int> word_map2;

			for (int j = i, start = i; j < S.length();j += word_len)
			{
				string s = S.substr(j, word_len);
				if (word_map.find(s) == word_map.end())
				{
					word_map2.clear();
					start = j + word_len;
					now_count = 0;
					continue;
				}
				while (word_map2[s] == word_map[s])
				{
					string s1 = S.substr(start, word_len);
					if (word_map2[s1] == word_map[s1])
						--now_count;
					--word_map2[s1];
					start += word_len;
				}
				++word_map2[s];
				if (word_map2[s] == word_map[s])
				{
					++now_count;
					if (now_count == word_map.size())
					{
						ans.push_back(start);
						--word_map2[S.substr(start, word_len)];
						start += word_len;
						--now_count;
					}
				}
			}
		}
		return ans;
	}
};


//*
int main()
{
	auto ans = Solution().findSubstring("aaa", vector<string>{"a", "b"});
	displayVector(ans);
	return 0;
}
//*/