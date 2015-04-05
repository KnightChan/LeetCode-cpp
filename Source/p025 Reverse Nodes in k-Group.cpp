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
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/
class Solution {
public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		ListNode *dummyHead = new ListNode(-1);
		dummyHead->next = head;
		ListNode *preTail = dummyHead;
		while (preTail->next)
		{
			ListNode *fast = preTail, *slow = preTail->next;
			int count;
			for (count = 0; fast->next&&count < k; fast = fast->next, count++);
			if (count < k) break;
			auto nextHead = fast->next;
			auto ht = reverseListNode(slow, fast);
			preTail->next = ht.first;
			ht.second->next = nextHead;
			preTail = ht.second;
		}
		return dummyHead->next;
	}

	pair<ListNode*, ListNode*> reverseListNode(ListNode *head, ListNode *tail)
	{
		if (!head)
			return make_pair(nullptr, nullptr);
		ListNode *newtail = head, *p = NULL;
		while (head != tail)
		{
			ListNode *t = head->next;
			head->next = p;
			p = head;
			head = t;
		}
		head->next = p;
		return make_pair(head, newtail);
	}
};

/*
int main()
{
	vector<int> v = { 1 ,2,3,4,5};
	ListNode *ans = Solution().reverseKGroup(makeList(v), 5);
	displayList(ans);
	return 0;
}
//*/