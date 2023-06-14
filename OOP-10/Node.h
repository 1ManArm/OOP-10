#pragma once
#include <iostream>
#include <string>
#include <vector>

class Node {
private:
	int _data;
public:
	Node* _next;
	Node* _prev;

	Node(int data);

	int getData();
};
