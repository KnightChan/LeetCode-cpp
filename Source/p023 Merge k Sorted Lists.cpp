#include "leetcode.h"

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

/**
	Merge k sorted linked lists and return it as one sorted list.Analyze and describe its complexity.

*/
class Solution {
public:
	class cmpGreater
	{
	public:
		bool operator()(const ListNode *a, const ListNode *b)
		{
			return a->val > b->val;
		}
	};
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		priority_queue<int, vector<ListNode*>, cmpGreater> pq;
		ListNode *dummyHead = new ListNode(-1), *p = dummyHead;
		for (auto ln : lists)
			if (ln)
				pq.push(ln);
		while (!pq.empty())
		{
			p->next = pq.top();
			p = p->next;
			pq.pop();
			if (p->next)
				pq.push(p->next);
		}
		return dummyHead->next;
	}
};

/*
int main()
{
	vector<vector<int>> vv = { { 1, 3, 7 }, { 2, 4, 5 }, {0, 6, 8} };
	vector<ListNode *> v1;
	for (auto v : vv)
		v1.push_back(makeList(v));
	ListNode *ans = Solution().mergeKLists(v1);
	displayList(ans);
	cout << endl;
	return 0;
}
//*/