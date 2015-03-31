#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	/**
	Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

	For example, given array S = {-1 2 1 -4}, and target = 1.

	The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

	*/
public:
	int threeSumClosest(vector<int> &num, int target) {
		int ans = 0, ansdif = INT_MAX;
		sort(num.begin(), num.end());
		for (int i = 0; i < num.size(); i++){
			int l = i + 1, r = num.size() - 1;
			bool last_true = false;
			while (l < r){
				int t = num[i] + num[l] + num[r];
				if (abs(t - target) < ansdif)
				{
					ansdif = abs(t - target);
					ans = t;
				}
				t < target ? ++l : --r;
			}
		}
		return ans;
	}
};

/*
int main()
{
	vector<int> v{ -1,2,1,4};
	int ans = Solution().threeSumClosest(v, 3);
	cout << ans << endl;
}
//*/