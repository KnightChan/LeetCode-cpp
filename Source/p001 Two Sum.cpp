#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
	/*
	Given an array of integers, find two numbers such that they add up to a specific target number.

	The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

	You may assume that each input would have exactly one solution.

	Input: numbers={2, 7, 11, 15}, target=9
	Output: index1=1, index2=2
	*/
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		unordered_map<int, int> hm;
		for (unsigned int i = 0; i < numbers.size(); i++)
			hm[numbers[i]] = i;
		vector<int> idx;
		for (unsigned int i = 0; i < numbers.size(); i++) {
			unordered_map<int, int>::iterator tmp = hm.find(target - numbers[i]);
			if (tmp != hm.end() && i != tmp->second){
				idx.push_back(i + 1);
				idx.push_back(tmp->second + 1);
				break;
			}
		}
		return idx;
	}
};


/*
int main()
{
	vector<int> v = { -1, -2, -3, -4, -5 };
	cout << Solution().twoSum(v, -8).front();
	return 0;
}
//*/