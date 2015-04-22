#include "leetcode.h"

/**
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

great
/    \
gr    eat
/ \    /  \
g   r  e   at
/ \
a   t

To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

rgeat
/    \
rg    eat
/ \    /  \
r   g  e   at
/ \
a   t

We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

rgtae
/    \
rg    tae
/ \    /  \
r   g  ta  e
/ \
t   a

We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

*/

class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1 == s2) return true;
		if (!anagrams(s1, s2)) return false;
		int len = s1.length();
		for (int i = 1; i <= len - 1; i++)
		{
			string s11 = s1.substr(0, i), s12 = s1.substr(i), s21 = s2.substr(0, i), s22 = s2.substr(i);
			if (isScramble(s11, s21) && isScramble(s12, s22)) return true;
			if (isScramble(s11, s2.substr(len - i)) && isScramble(s12, s2.substr(0, len - i))) return true;
		}
		return false;
	}

	bool anagrams(string s1, string s2) {
		unordered_map<char, int> mac;
		for (auto c : s1)
		{
			if (mac.find(c) == mac.end())
				mac[c] = 0;
			mac[c]++;
		}
		for (auto c : s2)
		{
			auto x = mac.find(c);
			if (x == mac.end()) return false;
			mac[c]--;
			if (mac[c] == 0) mac.erase(x);
		}
		if (mac.empty()) return true;
		return false;
	}
};


class Solution2 {
public:
	bool isScramble(string s1, string s2) {
		if (s1.length() != s2.length()) return false;
		int len = s1.length();
		vector<vector<vector<int> > > f(len + 1, vector<vector<int> >(len + 1, vector<int>(len + 1, -1)));
		return dfs(s1, s2, 0, 0, f);
	}

	bool dfs(string s1, string s2, int x, int y, vector<vector<vector<int>>> &f)
	{
		if (s1 == s2)
		{
			f[x][y][s1.length()] = 1;
			return true;
		}
		if (f[x][y][s1.length()] != -1)
			return f[x][y][s1.length()];
		if (!anagrams(s1, s2)) return false;
		int len = s1.length();
		for (int i = 1; i <= len - 1; i++)
		{
			string s11 = s1.substr(0, i), s12 = s1.substr(i), s21 = s2.substr(0, i), s22 = s2.substr(i);
			if ((dfs(s11, s21, x, y, f) && dfs(s12, s22, x + i, y + i, f))
				|| (dfs(s11, s2.substr(len - i), x, y + len - i, f) && dfs(s12, s2.substr(0, len - i), x + i, y, f)))
			{
				f[x][y][s1.length()] = 1;
				return true;
			}
		}
		f[x][y][s1.length()] = 0;
		return false;
	}

	bool anagrams(string s1, string s2) {
		unordered_map<char, int> mac;
		for (auto c : s1)
		{
			if (mac.find(c) == mac.end())
				mac[c] = 0;
			mac[c]++;
		}
		for (auto c : s2)
		{
			auto x = mac.find(c);
			if (x == mac.end()) return false;
			mac[c]--;
			if (mac[c] == 0) mac.erase(x);
		}
		if (mac.empty()) return true;
		return false;
	}
};