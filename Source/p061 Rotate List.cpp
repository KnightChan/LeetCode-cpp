#include "leetcode.h"
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