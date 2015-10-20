#include "leetcode.h"

/**
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3) 
findMedian() -> 2

*/

class MedianFinder {
public:
	priority_queue<int> big;
	priority_queue<int, vector<int>, greater<int>> small;
	// Adds a number into the data structure.
	void addNum(int num) {
		if (!big.empty() && num < big.top())
		{
			big.push(num);
			if (big.size() - small.size() == 1)
			{
				small.push(big.top());
				big.pop();
			}
		}
		else
		{
			small.push(num);
			if (small.size() - big.size() == 2)
			{
				big.push(small.top());
				small.pop();
			}
		}
	}

	// Returns the median of current data stream
	double findMedian() {
		if (small.size() == big.size())
			return (small.top() + big.top()) / 2.0;
		return small.top();
	}
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();