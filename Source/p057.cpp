#include "leetcode.h"

/**
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

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
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		intervals.push_back(newInterval);
		return merge(intervals);
	}

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

