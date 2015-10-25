#include "leetcode.h"

/**
Sort a linked list using insertion sort.
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
	ListNode* insertionSortList(ListNode* head) {
		auto dummy = new ListNode(-1);
		for (auto p = head; p; p = head)
		{
			head = p->next;
			for (auto q = dummy;; q = q->next)
			{
				if (!q->next || p->val <= q->next->val)
				{
					p->next = q->next;
					q->next = p;
					break;
				}
			}
		}
		return dummy->next;
	}
};
