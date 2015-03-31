#include <iostream>
using namespace std;

class Solution {
	/**
	Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "a*") ¡ú true
isMatch("aa", ".*") ¡ú true
isMatch("ab", ".*") ¡ú true
isMatch("aab", "c*a*b") ¡ú true

	*/
public:
	//8ms
	bool isMatch(const char *s, const char *p) {
		int ls = strlen(s), lp = strlen(p);
		bool **m = new bool*[ls + 1];
		for (int i = 0; i < ls + 1; i++)
			m[i] = new bool[lp + 1];
		for (int i = 0; i < ls + 1; i++)
			for (int j = 0; j < lp + 1; j++)
				m[i][j] = false;
		m[0][0] = true;
		for (int i = 0; i < ls + 1; i++)
			for (int j = 1; j < lp + 1; j++)
			if (p[j - 1] == '*'){
				if (j < 2) continue;
				m[i][j] |= m[i][j - 2];
				if (i < 1) continue;
				for (int k = i - 1; k >= 0 && eql(s[k], p[j - 2]); k--)
				m[i][j] |=  m[k][j - 2];
			}
			else{
				if (i < 1) continue;
				m[i][j] = m[i - 1][j - 1] & eql(s[i - 1], p[j - 1]);
			}
		return m[ls][lp];
	}

	//recursive, 8ms
	bool isMatch1(const char *s, const char *p) {
		int ls = strlen(s), lp = strlen(p);
		int **m = new int*[ls + 1];
		for (int i = 0; i < ls + 1; i++)
			m[i] = new int[lp + 1];
		for (int i = 0; i < ls + 1; i++)
			for (int j = 0; j < lp + 1; j++)
				m[i][j] = -1;
		m[0][0] = 1;
		return match(s, p, ls, lp, m);
	}
	
	bool match(const char *s, const char *p, int i, int j, int **m)
	{
		if (i < 0 || j < 0)
			return false;
		if (m[i][j] >= 0)
			return m[i][j];
		bool ans = false;
		if (p[j - 1] == '*'){
			ans = match(s, p, i, j - 2, m);
			for (int k = i - 1; k >= 0 && eql(s[k], p[j - 2]) && !ans; k--){
				ans = match(s, p, k, j, m);
			}
		}
		else{
			ans = eql(s[i - 1], p[j - 1]) && match(s, p, i - 1, j - 1, m);
		}
		m[i][j] = ans;
		return ans;
	}

	bool eql(char a, char b)
	{
		if (a == '.' || b == '.' || a == b)
			return true;
		return false;
	}
};

/*
int main()
{
	string sps[][2] = { { "aa", "a" }, { "aa", "aa" }, { "aaa", "aa" }, { "aa", "a*" }, { "aa", ".*" }, { "ab", ".*" }, { "aab", "c*a*b" }};

	for (int i = 0; i < 7; i++)
	{
		cout << sps[i][0].c_str() << ", " << sps[i][1].c_str() << ": ";
		cout << Solution().isMatch(sps[i][0].c_str(), sps[i][1].c_str()) << endl;
	}
return 0;
}
//*/