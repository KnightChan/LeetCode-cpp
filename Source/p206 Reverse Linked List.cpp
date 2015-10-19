#include "leetcode.h"

/**
Reverse a singly linked list.

click to show more hints.


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
    ListNode* reverseList(ListNode* head) {
        auto dummy = new ListNode(-1);
        for (auto p = head, pre = dummy; p;)
        {
            auto q = p;
            p = p->next;
            q->next = pre->next;
            pre->next = q;
        }
        return dummy->next;
    }
};
