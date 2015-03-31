#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

/**
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ¡Ü b ¡Ü c ¡Ü d)
The solution set must not contain duplicate quadruplets.

For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

A solution set is:
(-1,  0, 0, 1)
(-2, -1, 1, 2)
(-2,  0, 0, 2)
*/


//104ms
class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		vector<vector<int>> ans;
		for (int i = 0; i < num.size(); i++)
			if (i == 0 || num[i] != num[i - 1])
			for (int j = i + 1; j < num.size(); j++)
			if (j == i + 1 || num[j] != num[j - 1])
			{
			int l = j + 1, r = num.size() - 1, new_target = target - num[i] - num[j];
				bool last_true = false;
				while (l < r){
					if (num[l] + num[r] == new_target)
					{
						if (!last_true || num[l - 1] != num[l])
							ans.push_back(vector<int>{ num[i], num[j], num[l], num[r] });
						++l, --r;
						last_true = true;
					}
					else {
						num[l] + num[r] < new_target ? ++l : --r;
						last_true = false;
					}
				}
			}
		return ans;
	}
};

//198 ms
class Solution2 {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		vector<vector<int>> ans;
		unordered_map<int, vector<pair<int, int>>> twoSumMap;
		for (int i = 0; i < num.size(); i++)
			for (int j = i + 1; j < num.size(); j++)
				twoSumMap[num[i] + num[j]].push_back(make_pair(i, j));
		for (int i = 0; i < num.size(); i++)
		if (i == 0 || num[i] != num[i - 1])
		for (int j = i + 1; j < num.size(); j++)
		if (j == i + 1 || num[j] != num[j - 1])
		{
			if (num[i] + num[j] > target / 2)
				continue;
			auto twosum = twoSumMap.find(target - num[i] - num[j]);
			if (twosum == twoSumMap.end())
				continue;
			for (auto x34 : twosum->second)
			{
				if (j >= x34.first)
					continue;
				int a[4] = { num[i], num[j], num[x34.first], num[x34.second] };
				sort(a, a + 4);
				ans.push_back(vector < int > {a[0], a[1], a[2], a[3]});
			}
		}
		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());
		return ans;
	}
};

/*
int main()
{
	vector<int> v{ -1, 0, 1, 0, -2, 2};
	vector<int> v1{ 0,0,0,0 };
	vector<int> v2{};
	vector<vector<int> >ans = Solution2().fourSum(v, 0);
	for (auto v : ans)
	{
		for (auto x : v)
		cout << x << " ";
		cout << endl;
	}
}
//*/