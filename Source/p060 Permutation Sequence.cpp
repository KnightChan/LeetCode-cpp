#include "leetcode.h"

/**
The set [1,2,3,бн,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"

Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.


*/

class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int> nfacs(n + 1, 1);
		for (int i = 1; i <= n; i++) nfacs[i] = nfacs[i - 1] * i;
		vector<int> kth(n + 1, 0), used(n + 1, 0);
		k -= 1;
		for (int i = n; i > 0; i--)
		{
			kth[n - i] = k / nfacs[i - 1];
			k = k % nfacs[i - 1];
		}
		string res = "";
		for (int i = 0; i < n; i++)
		{
			for (int x = kth[i], j = 1; x >= 0 && j <= n; x--, j++)
			{
				while (used[j]) j++;
				if (x == 0)
				{
					res.push_back(j + '0');
					used[j] = 1;
				}
			}
		}
		return res;
	}
};

/*
int main()
{
	auto ans = Solution().getPermutation(3, 5);
	cout << ans << endl;
	return 0;
}
//*/