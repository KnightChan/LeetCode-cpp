#include "leetcode.h"

/**
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

1         3     3      2      1
\       /     /      / \      \
3     2     1      1   3      2
/     /       \                 \
2     1         2                 3


*/

class Solution {
public:
	int numTrees(int n) {
		vector<int> f(n + 1, 1);
		for (int i = 2; i <= n; i++)
		{
			f[i] = 0;
			for (int j = 0; j < i / 2; j++)
				f[i] += f[j] * f[i - j - 1];
			f[i] <<= 1;
			if (i & 1) f[i] += f[i / 2] * f[i / 2];
		}
		return f[n];
	}
};

/*
int main()
{
	cout << Solution().numTrees(3) << endl;
	return 0;
}
//*/