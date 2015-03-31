#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
 **/
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ansDummyHead = new ListNode(0);
        ListNode *t1 = l1, *t2 = l2, *tail = ansDummyHead;
        while (t1 && t2){
            tail->next = new ListNode(t1->val + t2->val);
            t1 = t1->next;
            t2 = t2->next;
            tail = tail->next;
        }
        if (t1)
            tail->next = t1;
        else
            tail->next = t2;
        t1 = ansDummyHead;
        int addone = 0;
        while (t1->next){
            t1->next->val += addone;
            addone = 0;
            if (t1->next->val >= 10){
                t1->next->val -= 10;
                addone = 1;
            }
            t1 = t1->next;
        }
        if (addone > 0)
            t1->next = new ListNode(addone);
        return ansDummyHead->next;
    }
};
