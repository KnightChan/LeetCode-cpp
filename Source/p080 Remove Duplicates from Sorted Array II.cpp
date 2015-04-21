#include "leetcode.h"

/**
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].

*/

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n < 3) return n;
		int now = 0, next = 0, last_i = 0, last_v = A[0];
		while (next < n)
		{
			while (next < n && A[next] == last_v && next - last_i > 1) next++;
			if (last_v != A[next])
			{
				last_v = A[next];
				last_i = next;
			}
			if (next < n) A[now++] = A[next++];
		}
		return now;
	}
};