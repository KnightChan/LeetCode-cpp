#include "leetcode.h"

/**
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

*/

/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/

bool cmpInterval(const Interval &a, const Interval &b)
{
	if (a.start < b.start) return true;
	else if (a.start == b.start) return a.end < b.end;
	return false;
}

class Solution {
public:
	vector<Interval> merge(vector<Interval> &intervals) {
		sort(intervals.begin(), intervals.end(), cmpInterval);
		vector<Interval> ans;
		for (int i = 0; i < intervals.size();)
		{
			Interval now(intervals[i].start, intervals[i].end);
			i++;
			while (i < intervals.size() && intervals[i].start <= now.end)
				now.end = max(now.end, intervals[i++].end);
			ans.push_back(now);
		}
		return ans;
	}
};

/*
int main()
{
	vector<Interval> v{ Interval(1, 3) };
	auto ans = Solution().merge(v);
	displayVector(ans);
	return 0;
}
//*/