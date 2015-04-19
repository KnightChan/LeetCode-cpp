#include "leetcode.h"

/**
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

*/

class Solution {
public:
	int minDistance(string word1, string word2) {
		int **f = new int*[word1.length() + 1];
		for (int i = 0; i < word1.length() + 1; i++)
			f[i] = new int[word2.length() + 1];
		for (int i = 0; i < word1.length() + 1; i++)
			f[i][0] = i;
		for (int i = 0; i < word2.length() + 1; i++)
			f[0][i] = i;
		for (int i = 1; i < word1.length() + 1; i++)
			for (int j = 1; j < word2.length() + 1; j++)
			{
			f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
			if (word1[i - 1] == word2[j - 1])
				f[i][j] = min(f[i][j], f[i - 1][j - 1]);
			else f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
			}
		int ans = f[word1.length()][word2.length()];
		for (int i = 0; i < word1.length() + 1; i++)
			delete[] f[i];
		delete f;
		return ans;
	}
};