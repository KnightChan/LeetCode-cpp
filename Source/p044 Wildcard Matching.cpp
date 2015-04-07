#include "leetcode.h"

/**
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "*") ¡ú true
isMatch("aa", "a*") ¡ú true
isMatch("ab", "?*") ¡ú true
isMatch("aab", "c*a*b") ¡ú false

*/

class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		vector<int> pos{};
		string sp(p);
		for (int i = 0; i < strlen(p); i++)
			if (p[i] == '*') pos.push_back(i);

		int first = 0;
		while (first < strlen(p) && p[first] != '*')
			if (first < strlen(s) && match(s[first], p[first]))
				++first;
			else return false;
		
		if (pos.empty()) return strlen(s) == strlen(p);

		for (int i = 0; i < pos.size() - 1; i++)
		{
			int this_index = kmp(s + first, sp.substr(pos[i] + 1, pos[i + 1] - pos[i] - 1).c_str());
			if (this_index < 0) return false;
			first += this_index + pos[i + 1] - pos[i] - 1;
		}
		int last = 1;
		while (strlen(p) >= last && p[strlen(p) - last] != '*')
			if (first + last <= strlen(s) && match(p[strlen(p) - last], s[strlen(s) - last]))
				++last;
			else return false;
		return true;
	}

	int kmp(const char *s, const char *p)
	{
		if (s == NULL || p == NULL) return -1;
		if (strlen(p) == 0) return 0;
		int *next = new int[strlen(p)];
		getNext(p, strlen(p), next);
		return search(s, p, next);
	}

	void getNext(const char *p, int n, int *next)
	{
		int j = -1;
		next[0] = -1;
		for (int i = 1; i < n; i++)
		{
			while (j >= 0 && !match(p[i], p[j + 1])) j = next[j];
			if (match(p[i], p[j + 1])) ++j;
			next[i] = j;
		}
	}

	int search(const char *s, const char *p, int *next)
	{
		int j = -1;
		for (int i = 0; i < strlen(s); i++)
		{
			while (j >= 0 && !match(s[i], p[j + 1])) j = next[j];
			if (match(s[i], p[j + 1])) ++j;
			if (j == strlen(p) - 1)
				return i - j;
		}
		return -1;
	}

	bool match(char a, char b)
	{
		if (a == '?' || b == '?' || a == b) return true;
		return false;
	}
};

/*
int main()
{
	vector<string> s1 = { "aa", "aa", "aaa", "aa", "aa", "ab", "aab", "abefcdgiescdfimde" };
	vector<string> s2 = { "a", "aa", "aa", "*", "a*", "?*", "c*a*b", "ab*cd?i*de" };
	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " " << s2[i] << "\t-> ";
		cout << (Solution().isMatch(s1[i].c_str(), s2[i].c_str()) ? "true" : "false") << endl;
	}
	return 0;
}
//*/
