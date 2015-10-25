#include "leetcode.h"

/**
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

*/

namespace LRUCashe1{

class LRUCache{
public:
	struct DoubleListNode {
		int val, key;
		DoubleListNode *prev, *next;
		DoubleListNode(int k, int value) : key(k), val(value), next(this), prev(this) {}

		void static del(DoubleListNode *node)
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;
			node->prev = NULL;
			node->next = NULL;
		}

		void static insert(DoubleListNode *node, DoubleListNode *newnode)
		{
			newnode->prev = node;
			newnode->next = node->next;
			node->next->prev = newnode;
			node->next = newnode;
		}

		void static print(DoubleListNode *node)
		{
			for (auto p = node->next; p != node; p = p->next)
			{
				cout << "(" << p->key << "," << p->val << ");";
			}
			cout << endl;
		}
	};

	int capacity;
	unordered_map<int, DoubleListNode*> m;
	DoubleListNode *head;

	LRUCache(int capacity) {
		this->capacity = capacity;
		head = new DoubleListNode(-1, -1);
	}

	int get(int key) {
		if (m.count(key))
		{
			DoubleListNode::del(m[key]);
			DoubleListNode::insert(head->prev, m[key]);
			return m[key]->val;
		}
		else return -1;
	}

	void set(int key, int value) {
		if (m.count(key))
		{
			m[key]->val = value;
			DoubleListNode::del(m[key]);
		}
		else
		{
			if (capacity == m.size())
			{
				m.erase(head->next->key);
				DoubleListNode::del(head->next);
			}
			m[key] = new DoubleListNode(key, value);
		}
		DoubleListNode::insert(head->prev, m[key]);
	}
};
}

class LRUCache{
public:
	int capacity;
	unordered_map<int, list<pair<int, int>>::iterator> m;
	list<pair<int, int>> head;

	LRUCache(int capacity) {
		this->capacity = capacity;
	}

	int get(int key) {
		if (m.count(key))
		{
			head.splice(head.end(), head, m[key]);
			return m[key]->second;
		}
		else return -1;
	}

	void set(int key, int value) {
		if (m.count(key))
		{
			m[key]->second = value;
			head.splice(head.end(), head, m[key]);
		}
		else
		{
			if (capacity == m.size())
			{
				m.erase(head.begin()->first);
				head.erase(head.begin());
			}
			head.push_back(make_pair(key, value));
			m[key] = --head.end();
		}
	}
};