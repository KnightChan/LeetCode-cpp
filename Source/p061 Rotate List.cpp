#include "leetcode.h"

/**
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

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
	ListNode *rotateRight(ListNode *head, int k) {
		if (head == NULL) return head;
		ListNode *fast = head, *slow = head;
		int len = 0;
		for (fast = head; fast != NULL; fast = fast->next) len++;
		k %= len;
		fast = head;
		while (k > 0 && fast->next)
		{
			fast = fast->next;
			--k;
		}
		if (k != 0) return head;
		while (fast->next)
		{
			fast = fast->next;
			slow = slow->next;
		}
		fast->next = head;
		head = slow->next;
		slow->next = NULL;
		return head;
	}
};