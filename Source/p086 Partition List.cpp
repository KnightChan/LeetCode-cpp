#include "leetcode.h"

/**
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode *partition(ListNode *head, int x) {
		ListNode *dummyHead1 = new ListNode(-1), *dummyHead2 = new ListNode(-1);
		ListNode *t1 = dummyHead1, *t2 = dummyHead2, *p = head;
		while (p)
		{
			if (p->val < x)
			{
				t1->next = p;
				t1 = t1->next;
			}
			else
			{
				t2->next = p;
				t2 = t2->next;
			}
			p = p->next;
		}
		t2->next = NULL;
		t1->next = dummyHead2->next;
		return dummyHead1->next;
	}
};