#include "leetcode.h"

void displayListNode(ListNode *ln)
{
	for (ListNode *p = ln; p != NULL; p = p->next)
		cout << p->val << " ";
	cout << endl;
}