#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	/**
	Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ¡Ü b ¡Ü c)
    The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

	*/
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int>> ans;
		sort(num.begin(), num.end());
		for (int i = 0; i < num.size(); i++)
		if (i == 0 || num[i] != num[i - 1]){
			int l = i + 1, r = num.size() - 1, target = -num[i];
			bool last_true = false;
			while (l < r){
				if (num[l] + num[r] == target)
				{
					if (!last_true || num[l - 1] != num[l])
						ans.push_back(vector<int>{ num[i], num[l], num[r] });
					++l, --r;
					last_true = true;
				}
				else {
					num[l] + num[r] < target ? ++l : --r;
					last_true = false;
				}
			}
		}
		return ans;
	}
};

/*
int main()
{
	vector<int> v{ -1, 0, 1, 2, -1, -4, -2, -2};
	vector<vector<int> >ans = Solution().threeSum(v);
	for (auto v : ans)
	{
		for (auto x : v)
			cout << x << " ";
		cout << endl;
	}
}
//*/