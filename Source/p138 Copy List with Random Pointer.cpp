#include "leetcode.h"

/**
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.


*/

/**
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*     int label;
*     RandomListNode *next, *random;
*     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
* };
*/
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		auto p = head;
		while (p)
		{
			auto newnext = new RandomListNode(p->label);
			newnext->next = p->next;
			p->next = newnext;
			p = p->next->next;
		}
		p = head;
		while (p)
		{
			if (p->random) p->next->random = p->random->next;
			p = p->next->next;
		}
		p = head;
		auto newh = new RandomListNode(-1);;
		auto p1 = newh;
		while (p)
		{
			p1->next = p->next;
			p1 = p1->next;
			p->next = p->next->next;
			p = p->next;
		}
		return newh->next;
	}
};
