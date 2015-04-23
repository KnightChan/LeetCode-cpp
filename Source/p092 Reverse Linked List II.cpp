#include "leetcode.h"

/**
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ¡Ü m ¡Ü n ¡Ü length of list.

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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode *dummyHead = new ListNode(-1);
		dummyHead->next = head;
		ListNode *pre = dummyHead;
		for (int k = 0; k < m - 1; k++, pre = pre->next);
		ListNode *p = pre->next, *tail = p;
		for (int k = m; k <= n; k++)
		{
			ListNode *t = p;
			p = p->next;
			t->next = pre->next;
			pre->next = t;
		}
		tail->next = p;
		return dummyHead->next;
	}
};