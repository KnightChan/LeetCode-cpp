class Solution {
public:
	/*
	 Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
	 */
	int singleNumber(int A[], int n) {
		int res = 0;
		for (int i = 0; i < n; i++)
			res ^= A[i];
		return res;
	}
};

#include <iostream>
using namespace std;

/*
int main()
{
	int a[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
	cout << Solution().singleNumber(a, sizeof(a)/sizeof(int));
	return 0;
}
//*/