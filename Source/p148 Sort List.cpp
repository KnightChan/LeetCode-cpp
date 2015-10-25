#include "leetcode.h"

/**
Sort a linked list in O(n log n) time using constant space complexity.

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
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode *dummyHead = new ListNode(0);
		ListNode *p = dummyHead;
		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				p->next = l1;
				l1 = l1->next;
			}
			else
			{
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		l1 ? p->next = l1 : p->next = l2;
		return dummyHead->next;
	}

	ListNode* sortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *p = head, *h1 = NULL, *h2 = NULL;
		for (int i = 0; p; p = head, i ^= 1)
		{
			head = head->next;
			p->next = i ? h1 : h2;
			if (i) h1 = p;
			else h2 = p;
		}
		return mergeTwoLists(sortList(h1), sortList(h2));
	}
};

