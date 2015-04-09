#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}

	friend ostream& operator<<(ostream& os, const Interval& f);
};




struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}; 

void displayList(ListNode *head);
ListNode * makeList(vector<int> v);

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


template<class T>
void displayVector2(vector<vector<T>> vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		displayVector<T>(vec[i]);
		cout << endl;
	}
}

template<class T>
void displayArray(T A, int n)
{
	cout << "[ ";
	for (int i = 0; i < n; ++i)
	{
		if (i != 0)
			cout << " , ";
		cout << A[i];
	}
	cout << " ]";
}