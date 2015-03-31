#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <list>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void displayListNode(ListNode *ln);

template<class T>
void displayVector(vector<T> vec)
{
	cout << "[ ";
	for (int i = 0; i < vec.size(); ++i)
	{
		if (i != 0)
			cout << " , ";
		cout << vec[i];
	}
	cout << " ]";
}

