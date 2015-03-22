#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	/**
	Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

	Note: You may not slant the container.
	*/
public:
	int maxArea(vector<int> &height) {
		int l = 0, r = height.size() - 1;
		int maxA = 0;
		while (l < r){
			maxA = max(maxA, min(height[l], height[r]) * (r - l));
			height[l] < height[r]?++l:--r;
		}
		return maxA;
	}

	int maxArea1(vector<int> &height) {
		int l = 0, r = height.size() - 1;
		int maxA = 0, minH = 0;
		while (l < r){
			minH = min(height[l], height[r]);
			maxA = max(maxA, minH * (r - l));
			while (height[l] <= minH && r > l)++l;
			while (height[r] <= minH && r > l)--r;
		}
		return maxA;
	}
};

/*
int main()
{
cout << Solution().isPalindrome(10) << endl;
return 0;
}
//*/