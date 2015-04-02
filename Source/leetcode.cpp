#include "leetcode.h"

ListNode* makeList(vector<int> data)
{
	ListNode *dummyHead = new ListNode(-1), *head = dummyHead;
	for (int i = data.size() - 1; i >= 0; --i)
	{
		{
			auto p = new ListNode(data[i]);
			p->next = head->next;
			head->next = p;
		}
	}
	return dummyHead->next;
}
void displayList(ListNode* head)
{
	cout << "[ ";
	auto p = head;
	while (p)
	{
		if (p != head)
			cout << " , ";
		cout << p->val;
		p = p->next;
	}
	cout << " ]";
} 