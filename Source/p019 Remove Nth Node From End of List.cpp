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
Given a linked list, remove the nth node from the end of list and return its head.

For example,

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass.

*/
class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		ListNode *first, *second, *dummyHead = new ListNode(0);
		dummyHead->next = head;
		for (first = dummyHead; first != NULL && n > 0; --n, first = first->next);
		if (first == NULL)
			return dummyHead->next;
		for (second = dummyHead; first->next != NULL; first = first->next, second = second->next);
		second->next = second->next->next;
		return dummyHead->next;
	}
};

/*
int main()
{
}
//*/