#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
	/**
	There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
	*/
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		double median = findKthMin(A, m, B, n, (m + n) / 2 + 1);
		if ((m + n) % 2 == 0)
			median = (median + findKthMin(A, m, B, n, (m + n) / 2)) / 2;
		return median;
	}

	double findKthMin(int A[], int m, int B[], int n, int k){
		if (m == 0)
			return B[k - 1];
		if (n == 0)
			return A[k - 1];
		if (k == 1)
			return min(A[0], B[0]);
		int ka = min(k / 2, m), kb = min(k / 2, n);
		if (A[ka - 1] > B[kb - 1])
			findKthMin(A, m, B + kb, n - kb, k - kb);
		else
			findKthMin(A + ka, m - ka, B, n, k - ka);
	}
};

/*
int main()
{
	int A[] = { 1 }, B[] = { 2, 3, 4};
	cout << Solution().findMedianSortedArrays(A, 1, B, 3);
	return 0;
}
//*/