#pragma once
#include "Node.h"

class LinkedList {
private:
	Node* _head;
	Node* _tail;
	int _size;
public:
	LinkedList();

	void addTail(int data);

	void addHead(int data);

	void showList();

	void deleteElement(int index);

	void deleteList();

	Node* findElement(int index);
};
