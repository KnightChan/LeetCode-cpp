#include "leetcode.h"

/**
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

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
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == NULL) return head;
		ListNode *dummyHead = new ListNode(-1);
		dummyHead->next = head;
		ListNode *pre = dummyHead, *p = head;
		int last_v = head->val - 1;
		while (p)
		{
			while (1)
			{
				if (p && p->next && p->val == p->next->val)
					last_v = p->val;
				else break;
				while ((p && p->val == last_v)) p = p->next;
			}
			pre->next = p;
			pre = p;
			if (!p) break;
			p = p->next;
		}
		return dummyHead->next;
	}
};