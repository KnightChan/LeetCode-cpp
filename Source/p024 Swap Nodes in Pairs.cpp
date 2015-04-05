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
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/
class Solution {
public:
	ListNode *swapPairs(ListNode *head) {
		ListNode *dummyHead = new ListNode(-1);
		dummyHead->next = head;
		ListNode *p = dummyHead;
		while (p->next && p->next->next)
		{
			ListNode *nexthead = p->next->next->next;
			ListNode *p1 = p->next, *p2 = p->next->next;
			p->next = p2;
			p2->next = p1;
			p1->next = nexthead;
			p = p->next->next;
		}
		return dummyHead->next;
	}
};