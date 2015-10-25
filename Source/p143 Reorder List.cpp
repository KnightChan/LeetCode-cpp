#include "leetcode.h"

/**
Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

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

	ListNode* reverseList(ListNode *head)
	{
		if (!head) return head;
		auto p = head->next;
		head->next = NULL;
		while (p)
		{
			auto next = p->next;
			p->next = head;
			head = p;
			p = next;
		}
		return head;
	}

	void reorderList(ListNode* head) {
		if (!head) return;
		int n = 0;
		for (auto p = head; p; p = p->next, n++);
		auto tail = head;
		for (int i = 1; i < (n + 1) / 2; i++, tail = tail->next);
		auto nexthead = reverseList(tail->next);
		tail->next = NULL;
		auto p = head;
		while (nexthead)
		{
			auto next = nexthead->next;
			nexthead->next = p->next;
			p->next = nexthead;
			p = p->next->next;
			nexthead = next;
		}
	}
};
