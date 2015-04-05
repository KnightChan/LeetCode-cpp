#include "leetcode.h"
/**
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of the pointer.
If you still see your function signature returns a char * or String, please click the reload button to reset your code definition.
*/
class Solution {
public:
	int strStr(char *haystack, char *needle) {
		if (!strlen(needle)) return 0;
		vector<int> ans = kmp(haystack, needle);
		if (!ans.size()) return -1;
		return ans[0];
	}

	vector<int> kmp(char *s, char *t)
	{
		int ls = strlen(s), lt = strlen(t);
		int j = -1;
		int *next = getNext(t);
		return search(s, t, next);
	}

	int* getNext(char *t)
	{
		int lt = strlen(t);
		int *next = new int[lt];
		int j = -1;
		next[0] = -1;
		for (int i = 1; i < lt; i++)
		{
			while (j >= 0 && t[i] != t[j + 1]) j = next[j];
			if (t[i] == t[j + 1]) ++j;
			next[i] = j;
		}
		return next;
	}

	vector<int> search(char *s, char *t, int *next)
	{
		vector<int> ans;
		int j = -1;
		for (int i = 0; i < strlen(s); i++)
		{
			while (j >= 0 && s[i] != t[j + 1]) j = next[j];
			if (s[i] == t[j + 1]) ++j;
			if (j == strlen(t) - 1)
			{
				ans.push_back(i - j);
				j = next[j];
			}
		}
		return ans;
	}
};

/*
int main()
{
	char* s = "aaa", *t = "a";
	int pos = Solution().strStr(s, t);
	cout << pos << endl;
	return 0;
}
//*/