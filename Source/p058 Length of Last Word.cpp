#include "leetcode.h"

/**
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.

*/

class Solution {
public:
	int lengthOfLastWord(const char *s) {
		bool findLast = false;
		int count = 0;
		int k = strlen(s) - 1;
		while (k >= 0)
		{
			if (s[k] == ' ')
			{
				if (findLast) return count;
			}
			else
			{
				if (!findLast) findLast = true;
				++count;
			}
			--k;
		}
		return count;
	}
};

//*
int main()
{

	return 0;
}
//*/